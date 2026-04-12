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
pair<int,int> p[10];

int main()
{
  int i,n;
  char name[10][25]={};
  int w,l,d;
  bool time=false;
  while(1){
    cin>>n;
    if(n==0)break;
    if(time)
      cout<<endl;
    rep(i,n){
      scanf("%s %d %d %d",name[i],&w,&l,&d);
      p[i].first=-1*(w*3+d);
      p[i].second=i;
    }
    sort(p,p+n);
    
    rep(i,n)
      printf("%s,%d\n",name[p[i].second],-1*(p[i].first));

    time=true;
  }

}