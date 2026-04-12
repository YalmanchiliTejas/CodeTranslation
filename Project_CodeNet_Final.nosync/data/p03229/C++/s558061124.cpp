#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using VI = vector<ll>;
using VV = vector<VI>;
using VS = vector<string>;

#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(i,b) FOR(i, 0, b)
#define ALL(v) (v).begin(), (v).end()
#define p(s) cout<<(s)<<endl
#define p2(s, t) cout << (s) << " " << (t) << endl
#define br() p("")
#define pn(s) cout << (#s) << " " << (s) << endl

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    // input
    ll N; cin >> N;
    VI A(N);
    rep(i, N){
        cin >> A.at(i);
    }
    sort(ALL(A));

    if(N%2==0){
      // N型
      ll sum = 0;
      // 係数2
      ll L = N-2;
      rep(i, L/2){
        sum -= 2 * A[i];
        sum += 2 * A[N-1-i];
      }
      sum += A[N/2];
      sum -= A[N/2-1];
      p(sum);
    }
    else{
      // M型
      ll sum = 0;
      rep(i, (N+1)/2){
        ll c;
        if(i==N/2 || i==N/2-1){
          c = 1;
        }else{
          c = 2;
        }
        sum -= c * A[i];
      }
      FOR(i, (N+1)/2, N){
        sum += 2*A[i];
      }

      // W型
      ll sum2 = 0;
      FOR(i, N/2, N){
        ll c;
        if(i==N/2 || i==N/2+1){
          c = 1;
        }else{
          c = 2;
        }
        sum2 += c * A[i];
      }
      FOR(i, 0, N/2){
        sum2 -= 2 * A[i];
      }

      ll ans = max(sum, sum2);
      p(ans);
    }
    
    return 0;
}