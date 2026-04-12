#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 1e9+1;
const ll INFll = (ll)1e18+1;
ll MOD=1e9+7;


int main(){
  ll N,X,M;
  cin>>N>>X>>M;
  ll sumtmp(0),nowtmp(X);
  for(int i(0);i<M;i++){
    sumtmp += nowtmp;
    nowtmp = nowtmp*nowtmp%M;
    if(nowtmp==0) {
      cout << sumtmp << endl;
      return 0;
    }
  }

  int used[100001] = {0};
  ll now = X;
  while(used[now] != 1){
    used[now] = 1;
    now = now*now%M;
  }
  ll cnt(0);
  ll sum(0);
  ll start = now;
  do{
    cnt++;
    now = now*now%M;
    sum += now;
  }while(now != start);
  //cout << now << " " << sum << " " << cnt << endl;
  ll hazime(0),owari(0),hazime_cnt(0);
  now = X;
  while(now != start){
    hazime_cnt++;
    hazime += now%M;
    now = now*now%M;
  }
  now = start;
  for(int i(0);i<(N-hazime_cnt)%cnt;i++){
    owari += now; 
    now = now*now%M;
  }
  ll ans = hazime + sum * ((N-hazime_cnt)/cnt) + owari;
  cout << ans << endl;
  return 0;
}

