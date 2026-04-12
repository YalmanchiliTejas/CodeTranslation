#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#pragma region Macros
#define FOR(i, m, n) for (ll i = (ll)(m); i < (ll)(n); i++)
#define rep(i, n) FOR(i, 0, n)

template <class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template <class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

template <class T> string join(const T &v, const string delim = ",")
{
    if (v.empty())
        return "";

    ostringstream res;
    res << v[0];
    for (int i = 1; i < v.size(); i++)
    {
        res << delim << v[i];
    }
    return res.str();
}

#pragma endregion Macros

ll solv(int N, vector<ll> &A){
    ll mod = 1e9+7;

    vector<ll> s(N+1,0);
    rep(i,N) {
        s[i+1] = s[i] + A[i];
        s[i+1] %= mod;
    }

    ll ans = 0;
    rep(i,N-1){
        ans += A[i] * (mod+s[N]-s[i+1]); 
        ans %= mod;
    }

    return ans;
}

ll simple(int N, vector<ll> &A){
    ll mod = 1e9+7;
    ll ans = 0;

    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            ans += (A[i]*A[j])%mod; 
            ans %= mod;
        }
    }
    return ans;
}

void input(int &N, vector<ll> &A){
    cin >> N;
    A.resize(N);
    rep(i,N) cin >> A[i];
}

void input2(int &N, vector<ll> &A){
    random_device rnd;
    N = 2000;
    A.resize(N);
    rep(i,N){
        A[i] =  rnd()%1000000000;
    }
}



int main()
{
    int N;
    vector<ll> A;

    input(N,A);
//    input2(N,A);
    ll ans = solv(N,A);
//    ll ans = simple(N,A);

/*    if(solv(N,A) != simple(N,A)){
        cerr << join(A) << endl;
        cerr << solv(N,A) << endl;
        cerr << simple(N,A) << endl;
    }*/

    cout << ans << endl;

}
