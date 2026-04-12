#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
#include<utility>
#include<memory>
#include<cmath>
#include<stack>

#define ALL(g) (g).begin(),(g).end()
#define REP(i, x, n) for(int i = x; i < n; i++)
#define rep(i,n) REP(i,0,n)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define pb push_back
#define DEBUG false

using namespace std;
 
typedef long long ll;
typedef pair<int,int> P;
const int mod=1e9+7,INF=1<<30;
const double EPS=1e-12,PI=3.1415926535897932384626;
const ll LINF=1LL<<60,lmod=1e9+7;
const int MAX_N=200005;

int b[MAX_N*2];

int main(){
  int n;
  cin >> n ;
  bool rev; //trueの時逆向き
  int l = MAX_N-1; 
  int r = MAX_N;
  rep(i,n){
    rev = (i%2==1);
    if(!rev){
      scanf("%d",&b[r++]);
    }else{
      scanf("%d",&b[l--]);
    }
  }
  rev = (n%2==1);
  if(!rev){
    rep(i,n-1) printf("%d ",b[l+i+1]);
    printf("%d\n",b[r-1]);
  }else{
    rep(i,n-1) printf("%d ",b[r-i-1]);
    printf("%d\n",b[l+1]);
  }
  return 0;
}