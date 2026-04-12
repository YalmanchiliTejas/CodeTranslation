#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
#define ALL(x) (x).begin(), (x).end()
#define REP(i ,n) for(int i = 0; i < (int)(n); i++)
#define pb push_back
typedef vector<int>vint;
typedef vector<ll>vll;
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}
int main()
{
    ll A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;

    ll ans = 0;
    if(X > Y){
        if(A + B >= 2*C){
            ans += 2*C*Y;
        }else{
            ans += (A + B)*Y;
        }
        X -= Y;
        Y = 0;
        if(A >= 2*C){
            ans += 2*C*X;
        }else{
            ans += A*X;
        }
    }else{
        if(A + B >= 2*C){
            ans += 2*C*X;
        }else{
            ans += (A + B)*X;
        }
        Y -= X;
        X = 0;
        if(B >= 2*C){
            ans += 2*C*Y;
        }else{
            ans += B*Y;
        }
    }
    cout << ans << endl;
}