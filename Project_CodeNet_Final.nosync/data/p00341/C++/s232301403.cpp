#include<cstdio>
#include<algorithm>

int main()
{

  int A[12];
  
  for(int i=0; i<12; i++)
    {
      scanf("%d", &A[i]);
    }
  

  /*  for(i=0; i<12; i++)
    {
      minj=i;
	for(j=i+1; j<12; j++)
	  {
	    if(A[j]<A[minj]) minj=j;
	  }

      A[i]=tmp;
      A[minj]=tmp;
      A[minj]=A[i];
      }   */



  
  std::sort(A,A+12);

  /* for(int i=0; i<12; i++)
    printf("%d ", A[i]);
  */
  if(A[0]==A[3]&&A[4]==A[7]&&A[8]==A[11])
    {
      printf("yes\n");
    }

  else printf("no\n");
  
  
}

