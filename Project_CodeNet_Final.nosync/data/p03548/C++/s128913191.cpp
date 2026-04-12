#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for(int i = 0; i < (int)(n); i++)

int main(){
  int x,y,z;
  cin>>x>>y>>z;
  int cnt=0;
  x-=z;
  while (true)
  {
    /* code */
    if (x>=y+z)
    {
      /* code */
      cnt++;
      x-=y+z;
    }
    else
    {
      break;
    }
    
    
  }
  cout<<cnt<<endl;
  
  }