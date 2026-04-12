#include <bits/stdc++.h>
using namespace std;
 
int main()
{
  int h,w;
  cin>>h>>w;
  
  string board[110];
  
  for(int i=0;i<h;i++)
  {
       cin>>board[i];
  }
 
 bool goodx[h];
 bool goody[w];
  
  for(int i=0;i<h;i++)
  { goodx[i]=false;}
    
  for(int i=0;i<w;i++)
  { goody[i]=false;}
  
  for(int i=0;i<h;i++)
  {
      for(int j=0;j<w;j++)
      {
          if(board[i][j]=='#')
          {
               goodx[i]=true;
               goody[j]=true;
          }
      }      
  }
  
  
  
  for(int i=0;i<h;i++)
  {
     if(goodx[i])
     {
      for(int j=0;j<w;j++)
      {
        if(goody[j])
        {
          cout<<board[i][j];
        }
       }  
     }
        cout<<endl;
      
  }
}