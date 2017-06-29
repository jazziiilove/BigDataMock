/* 
* * * * * * * * * * * * * * * * * * * * * * *
* Deadline: -	                            *
* Programmer: Baran Topal                   *
* Solution name: HugeFileMock for Routing   *
* Project name: HugeFileMock	            *
* Source Files: HugeFileMock.cpp			*
*                                           *      
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*	                                                                                         *
*  LICENSE: This source file is subject to have the protection of GNU General                *
*	Public License. You can distribute the code freely but storing this license information. *
*	Contact Baran Topal if you have any questions. barantopal@barantopal.com                 *
*	                                                                                         *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/

# include <stdio.h>
# include <string.h>
# include <time.h>
# include <stdlib.h>
# include <math.h>

// function declarations
// constructing the file content
void construct(char c, FILE *pfile);

// checking duplicate prefixes
int * check_key(int a[], int * filesize);

void main()
{		

	// file pointer
	FILE * pfile = fopen("bigfile.txt","wt");		 

	// randomize setp
	srand(time(NULL));

	// loop over A to Z
	for(int i = 65; i <= 90; i++)
	{
		construct(i, pfile);
	}

	// close the file
	fclose(pfile);
}

// function to remove the duplicate keys
int * check_key(int a[], int *filesize) 
{ 
	int i, j, k;

	int *p = a;
	for(i = 0;i < *filesize; i++)
	{
		for(j = 0; j < *filesize; j++)
		{
			if(i==j)
			{
				continue;
			}
			else if(*(p+i) == *(p+j))
			{
				k = j;
				(*filesize)--;
				while(k < *filesize)
				{
					*(p+k) = *(p+k+1);
					k++;
				}
				j=0;
			}
		}
	}
	return p;
}

// construct the file content
void construct(char c, FILE *pfile)
{		
	fprintf(pfile,"Operator %c:\n",c);
	const int filesize = 65000;
	int j = 1;
	int r[filesize];
	double p[filesize];

	for(int i = 0; i < filesize;i++)
	{
		r[i] = rand() % (j*1000) + 10;
		p[i] = ((double)(rand() % j)/(double)RAND_MAX+rand() % (j));
		j++;
	}
	int size = filesize;

	int * m = check_key(r, &size); //check whole array content

	// fprintf the modified array content
	for(int i = 0; i < size; i++)
	{
		fprintf(pfile, "%d\t %.2f\n", m[i], p[i]);
	}
}