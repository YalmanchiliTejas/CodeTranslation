#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main()
{
  ll N;
  cin >> N;
  vector<ll> A(N);
  REP(i, N) cin >> A[i];
  sort(ALL(A));
  ll ans = 0;
  ll cnt = A[0]*2;
  ll x=A[0],y=A[0];
  REP(i,(N-1)/2){
    if(i%2==0){
      ans+=abs(cnt-A[N-1-i]-A[N-2-i]);
      cnt=A[N-1-i]+A[N-2-i];
      if(i==(N-1)/2-1){
        x=A[N-1-i];
        y=A[N-2-i];
      }
    }else{
      ans+=abs(cnt-A[i]-A[i+1]);
      cnt=A[i]+A[i+1];
      if(i==(N-1)/2-1){
        x=A[i];
        y=A[i+1];
      }
    }
  }

  if(N%2==0){
    if(N%4==0){
      ans+=max(abs(x-A[N/2-1]),abs(y-A[N/2-1]));
    }else{
      ans+=max(abs(x-A[N/2]),abs(y-A[N/2]));
    }
  }
  ll ans2 = 0;
  ll cnt2 = A[N-1]*2;
  ll x2=A[N-1],y2=A[N-1];
  REP(i,(N-1)/2){
    if(i%2==0){
      ans2+=abs(cnt2-A[i]-A[i+1]);
      cnt2=A[i]+A[i+1];
      if(i==(N-1)/2-1){
        x2=A[i];
        y2=A[i+1];
      }
    }else{
      ans2+=abs(cnt2-A[N-1-i]-A[N-2-i]);
      cnt2=A[N-1-i]+A[N-2-i];
      if(i==(N-1)/2-1){
        x2=A[N-1-i];
        y2=A[N-2-i];
      }
    }
  }

  if(N%2==0){
    if(N%4==0){
      ans2+=max(abs(x2-A[N/2]),abs(y2-A[N/2]));
    }else{
      ans2+=max(abs(x2-A[N/2-1]),abs(y2-A[N/2-1]));
    }
  }

  cout << max(ans,ans2) << endl;
}