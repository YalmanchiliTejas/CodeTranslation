#include<bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  cin>>n;
  vector<int>v(n);
  for(int i=0;i<n;i++)
  {
    cin>>v[i];
  }
  int c=0,f=0;
  for(int i=0;i<n;i++)
  {
    	for(int j=0;j<i;j++)
        {
          if(v[j]<=v[i])
            f=1;
          else{
            f=0;
            break;
          }
          
        }
   		 if(f==1){
            c++;
            f=0;}
  }
  cout<<c+1<<endl;
  return 0;
}