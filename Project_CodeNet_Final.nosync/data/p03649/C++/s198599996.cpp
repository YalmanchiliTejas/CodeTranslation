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
const ll LINF=1LL<<60;
const int MAX_N=51;

ll x[MAX_N];
int N;

ll div_floor(ll a,ll b){
  return (a+b-1)/b;
}

ll judge(ll k){
  ll sum = 0;
  rep(i,N){
      ll _temp = x[i]+k+1-N;
      sum += div_floor(_temp,N+1);
  }
  return sum;
}

int main(){
  cin >> N ;
  rep(i,N) scanf("%lld",&x[i]);
  ll ok,ng,mid;
  ok = 50*1e16;
  ng = -1;
  int cnt = 0;
  rep(i,500){
    mid = (ok+ng)/2;
    bool flag;
    rep(i,N+1){
      flag=false;
      if(mid-i<0) break;
      ll a = judge(mid-i);
      if(a<=mid-i){
        ok = mid-i;
        flag = true;
      }
    }
    if(!flag) ng = mid;
    //cout << ok << endl;
  }
  cout << ok << endl;
  return 0;
}