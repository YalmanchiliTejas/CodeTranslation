#include<iostream>
#include<string.h>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<cmath>
#include<utility>
#define ll long long int
#define ld long double
#define INF 1000000000
#define EPS 0.0000000001
#define rep(i,n) for(i=0;i<n;i++)
using namespace std;
typedef pair<int, int> P;

string str;

int main()
{
  int n,num;
  int x,y;

  while(1){
    cin>>n;
    if(n==0)break;
    int squre[15][15]={};
    x=n/2+1;
    y=n/2;
    for(num=1;num<=n*n;num++){
      squre[x][y]=num;
      x=(x+1)%n;
      y=(y+1)%n;
      if(squre[x][y]){
	x=(x+1)%n;
	y=(y+n-1)%n;
      }
    }
    int i,j;
    rep(i,n){
      rep(j,n)
	printf("%4d",squre[i][j]);
      puts("");
    }
  }
}