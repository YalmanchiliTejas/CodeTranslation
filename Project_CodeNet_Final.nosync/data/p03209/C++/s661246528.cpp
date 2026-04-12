#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>

#define REP(i,n) for(auto i=0;i<n;++i)
#define REPR(i,n) for(auto i=n;i>=0;--i)
#define REPI(itr,v) for(auto itr=v.begin();itr!=v.end();++itr)
#define REPIR(itr,v) for(auto itr=v.rbegin();itr!=v.rend();++itr)
#define FOR(i,a,b) for(auto i=a;i<b;++i)
#define SORT(v,n) sort(v, v+n)
#define SORTV(v) sort(v.begin(), v.end())
#define ALL(v) v.begin(),v.end()
#define llong long long
#define ll long long
#define INF 999999999
#define MOD 1000000007
#define pb push_back
#define pf push_front
#define MP make_pair
#define SV(n,v) {int tmp;for(int i=0;i<n;++i){scanf("%d",&tmp);v.push_back(tmp);}}

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

using namespace std;

typedef pair<int,int> pii;

llong len[51] = {}, p[51];
llong n, x;

llong solve(int sou, llong num, llong sum){
  if(sou == 0) return sum+1;

  if(num == 1){
    return sum;
  }else if(num == len[sou-1]+2){
    return sum+1+p[sou-1];
  }else if(num == len[sou]){
    return sum + p[sou];
  }else if(num > 1 && num < len[sou-1]+2){
    return solve(sou-1, num-1, sum);
  }else{
    return solve(sou-1, num-2-len[sou-1], sum+p[sou-1]+1);
  }
}

int main(){

  cin >> n >> x;

  len[0] = 1;
  p[0] = 1;
  REP(i,50){
    len[i+1] = len[i] * 2 + 3;
    p[i+1] = p[i] * 2 + 1;
  }
  cout << solve(n,x,0) << endl;
  return 0;
}

