#include<iostream>
#include<algorithm>
using namespace std;
#define SIZE 100001
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)

int table[SIZE];
int solve(int n,int cnum,int *coin){
  rep(i,n+1)table[i]=n;
  table[0]=0;
  rep(i,n){
    rep(j,cnum){
      if ( i+coin[j]>n)break;
      table[i+coin[j]]=min(table[i]+1,table[i+coin[j]]);
    }
  }
  return table[n];
}

main(){
  int n,m;
  while(cin>>n>>m&&n){
    int in[n],cnum=1<<n,coin[1<<n];
    rep(i,n)cin>>in[i];
    rep(i,cnum){
      coin[i]=0;
      rep(j,n){
	if ( ( (1<<j)&i)!=0)coin[i]+=in[j];
      }
    }
    sort(coin,coin+cnum);
    cout << solve(m,cnum,coin) << endl;
  }
  return false;
}