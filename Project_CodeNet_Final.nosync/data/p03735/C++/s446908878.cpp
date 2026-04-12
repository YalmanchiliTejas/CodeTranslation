#include <iostream>
#include <map>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int n;
P ball[200001];
int idx;
ll solve1(){
  ll Rmin = ball[0].first;
  ll Bmax = ball[idx].second;
  ll Rmax = ball[n-1].first;
  ll Bmin = Bmax;
  for(int i=0;i<n;++i)
    Bmin = min(Bmin,ball[i].second);
  return (Rmax-Rmin)*(Bmax-Bmin);
}

ll solve2(){
  ll Rmin = ball[0].first;
  ll Rmax = ball[idx].second;
  set<P> S;
  S.insert(P(ball[0].second,1000000));
  for(int i=0;i<n;++i)
    if(i)
      S.insert(P(ball[i].second,i));
  ll ret = 1LL<<60;
  while(1){
    ll dif = S.rbegin()->first - S.begin()->first;
    ret = min(ret, (Rmax-Rmin)*dif);
    auto a = *S.rbegin();
    S.erase(*S.rbegin());
    if(a.second>=1000000) break;
    S.insert(P(ball[a.second].first,1000000));
  }
  return ret;
}
int input(){
  int x;
  scanf("%d",&x);
  return x;
}
int main(){
  scanf("%d",&n);
  for(int i=0;i<n;++i){
    ball[i]=P(input(),input());
    if(ball[i].first > ball[i].second)
      swap(ball[i].first, ball[i].second);
  }
  sort(ball,ball+n);
  int MAX = 0;
  idx = -1;
  for(int i=0;i<n;++i){
    if(MAX < ball[i].second){
      MAX = ball[i].second;
      idx = i;
    }
  }
  //  cout<<solve1() << " " << solve2() << endl;
  cout << min(solve1(),solve2()) << endl;
  
  return 0;
}
