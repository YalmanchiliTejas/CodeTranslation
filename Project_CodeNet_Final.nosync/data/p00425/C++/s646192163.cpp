#include<iostream>

using namespace std;

int main()
{
  int n;
  for(;cin>>n,n;)
    {
      int dice[]={1,2,3,5,4,6};//top,S,E,N,W,botton;
      int sum=1;
      for(int i=0;i<n;i++)
	{
	  string move;
	  cin>>move;
	  int tmp;
	  if(move=="North")
	    {
	      tmp=dice[0];
	      dice[0]=dice[1];
	      dice[1]=dice[5];
	      dice[5]=dice[3];
	      dice[3]=tmp;
	    }
	  if(move=="East")
	    {
	      tmp=dice[0];
	      dice[0]=dice[4];
	      dice[4]=dice[5];
	      dice[5]=dice[2];
	      dice[2]=tmp;
	    }
	  if(move=="South")
	    {
	      tmp=dice[0];
	      dice[0]=dice[3];
	      dice[3]=dice[5];
	      dice[5]=dice[1];
	      dice[1]=tmp;

	    }
	  if(move=="West")
	    {
	      tmp=dice[0];
	      dice[0]=dice[2];
	      dice[2]=dice[5];
	      dice[5]=dice[4];
	      dice[4]=tmp;
	    }
	  if(move=="Right")
	    {
	      tmp=dice[1];
	      dice[1]=dice[2];
	      dice[2]=dice[3];
	      dice[3]=dice[4];
	      dice[4]=tmp;
	    }
	  if(move=="Left")
	    {
	      tmp=dice[1];
	      dice[1]=dice[4];
	      dice[4]=dice[3];
	      dice[3]=dice[2];
	      dice[2]=tmp;
	    }	  
	  sum+=dice[0];
	}
      cout<<sum<<endl;
    }
}