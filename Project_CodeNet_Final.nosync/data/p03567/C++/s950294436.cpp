#include<stdio.h>
#include<iostream>
using namespace std;
int main(void)
{
  char st[5];
  int ans=0;
  scanf("%s",st);
  for(int i=0;i<5;i++)
    {
      if(st[i]=='A')
	{
	
	  if(st[i+1]=='C')
	    {
	      ans=1;
	    }
	}
    }

  if(ans==0)
    {
      printf("No\n");
    }
  else
    {
      printf("Yes\n");
    }
  return 0;
}