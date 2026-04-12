#include<iostream>
#include<string.h>
#include<string>
#include<cstdio>
#include<stdlib.h>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<cmath>
#include<utility>
#include<set>
#define ll long long int
#define ld long double
#define INF 1000000000
#define EPS 0.0000000001
#define rep(i,n) for(i=0;i<n;i++)
using namespace std;
typedef pair<int, int> pii;

int main()
{
  int i,j;
  int h,w;
  char a[10][10];

  cin>>h>>w;
  rep(i,h)
    scanf("%s",a[i]);
  rep(j,w)
    a[h][j]='.';
  rep(i,h)
    a[i][w]='.';

  a[0][0]='.';
  i=0;
  j=0;
  while(1){
    if(i==h-1 && j==w-1)break;
    if(a[i][j+1]=='#' && a[i+1][j]=='#'){
      cout<<"Impossible"<<endl;
      return 0;
    }
    if(a[i][j+1]=='.' && a[i+1][j]=='.'){
      cout<<"Impossible"<<endl;
      return 0;
    }
    if(a[i][j+1]=='#'){
      j++;
      a[i][j]='.';
    }else{
      i++;
      a[i][j]='.';
    }
  }
  rep(i,h)rep(j,w)
    if(a[i][j]=='#'){
      cout<<"Impossible"<<endl;
      return 0;
    }
  cout<<"Possible"<<endl;
}


