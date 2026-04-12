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

VI A; // 厚さ
VI P; // パティ数

ll f(ll N, ll X){
  if(N==0){
    if(X==0){
      return 0;
    }else{
      return 1;
    }
  }
  if(X==0 || X==1) return 0;
  else if(1<X && X<=1+A[N-1]) return f(N-1, X-1);
  else if(X==2+A[N-1]) return P[N-1]+1; // ちょうど真ん中まで食べる
  else if(2+A[N-1]<X && X<=2+2*A[N-1]) return P[N-1]+1+f(N-1, X-2-A[N-1]);
  else if(X==3+2*A[N-1]) return 2*P[N-1]+1;
  else p("something wrong");
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    // input
    ll N, X;
    cin >> N >> X;
    A.resize(51);
    P.resize(51);

    A[0]=1;
    P[0]=1;
    FOR(i, 1, 51){
      A[i] = 2*A[i-1]+3;
      P[i] = 2*P[i-1]+1;
    }

    ll ans = f(N, X);
    p(ans);
    
    return 0;
}