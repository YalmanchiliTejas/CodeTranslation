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

#define REP(i,n) for(int i=0;i<n;++i)
#define REPR(i,n) for(int i=n;i>=0;--i)
#define REPI(itr,v) for(auto itr=v.begin();itr!=v.end();++itr)
#define REPIR(itr,v) for(auto itr=v.rbegin();itr!=v.rend();++itr)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define SORT(v,n) sort(v, v+n)
#define SORTV(v) sort(v.begin(), v.end())
#define ALL(v) v.begin(),v.end()
#define llong long long
#define ll long long
#define INF 999999999
#define SUR 1000000007
#define pb(a) push_back(a)
#define pf(a) push_front(a)
#define MP make_pair
#define SV(n,v) {int tmp;for(int i=0;i<n;++i){scanf("%d",&tmp);v.push_back(tmp);}}

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

using namespace std;

typedef pair<int,int> pii;

int main(){

  llong n, k;
  scanf("%lld %lld", &n, &k);

  if(k == 0){
    printf("%lld\n", n * n);
    return 0;
  }

  llong ans = 0;
  FOR(i,k+1,n+1){
    llong count = (n - k) / i;
    llong num = i - k;
    ans += num;
    if(count >= 2){
      ans += num * (count - 1);
    }
    //cout << count << " " << ans << endl;
    if(count >= 1){
    if(n % i >= k){
      ans += (n % i) - k + 1;
    }else{
      ans += num;
    }
    //cout << ans << endl;
  }
  }
  printf("%lld\n", ans);
  return 0;
}

