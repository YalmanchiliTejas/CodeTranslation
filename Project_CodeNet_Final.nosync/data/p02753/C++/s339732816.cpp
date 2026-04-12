#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<string.h>
#include<algorithm>
#include <cmath>

using namespace std;

char S[3];

int main()
{
  cin>>S;
  
  if(S[0]==S[1] && S[1]==S[2])
  {
    cout <<"No";
    return 0;
    
  }
  else
  {
    cout <<"Yes";
    return 0;
  }
  
  
  
  
}