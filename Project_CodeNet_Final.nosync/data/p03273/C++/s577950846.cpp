#include <bits/stdc++.h>
#include <algorithm>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstdio>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define DEBUG
#define PI 3.141592653589793238462643383279

#define _GLIBCXX_DEBUG
#ifdef DEBUG
#define s(...) show(__VA_ARGS__);
#define sl(...) show(__VA_ARGS__);cout<<endl;
#else
#define s(...)
#define sl(...)
#endif
void show() {}
template <class Head,class... Args>void show(Head t,Args... args){std::cout<<t<<" ";show(args...);}
#define REP(i, n) for(ll i = 0; i < n; i++)
#define REPR(i, n) for(ll i = n; i >= 0; i--)
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define REP1(i, n) for(ll i = 1; i <= n; i++)
#define REPR1(i, n) for(ll i = n; i >= 1; i--)
#define FOR1(i, m, n) for(ll i = m; i <= n; i++)
const ld INF = 1e9+123;
#define VEC(type,A,N) vector<type> A(N)
#define VECi(type,A,N,i) vector<type> A(N,i)
#define VEC2(type,A,N,M) vector<vector<type>> A(N,vector<type>(M))
#define VEC2i(type,A,N,M,i) vector<vector<type>> A(N,vector<type>(M,i))
#define ALL(v) v.begin(), v.end()
ll frac(ll k){
    int s = 1;
    for (ll i=1; i<=k; ++i)s *= i;
    return s;
}
ll gcd(ll a, ll b){
   if (a%b==0)return(b);
   else return(gcd(b, a%b));
}
ll lcm(ll a,ll b){
    return a*b/gcd(a,b);
}
ll antidiv(ll N,ll C,ll D){
    return N-floor(N/C)-floor(N/D)+floor(N/lcm(C,D));
}
vector<ll> yakusuu(ll N){
    vector<ll> ret;
    for (ll i = 1; i * i <= N; i++) {
        if (N % i == 0) {
            ret.push_back(i);
            if (i * i != N) ret.push_back(N / i);
        }
    }
    sort(ret.begin(), ret.end());
    return ret;
}
int main(){
    ll H,W;
    cin>>H>>W;
    
    VEC(string,a,0);
    VECi(bool,addf,W,false);
    REP(i,H){
        bool f=true;
        string t;
        cin>>t;
        REP(j,W){
            if(t[j]=='#'){
                if(f){
                    a.push_back(t);
                    f=false;
                }
                addf[j]=true;
            }
            //s(addf[j]);
        }
        //sl();
    }
    
    VEC(string,ans,0);
    REP(i,a.size()){
        ans.push_back("");
        REP(j,a[0].size()){
            if(addf[j]){
                ans[i]+=a[i][j];
            }
        }
    }
    
    REP(i,ans.size()){
        cout<<ans[i]<<endl;
    }
    //cout<<fixed<<setprecision(32)<<m;
    //sort(ALL(C),[](auto& a, auto& b) {return a[2] < b[2];});
    //if(equal(D.begin(), D.end()-1, K.begin()))cout<<"Yes";else cout<<"No";
    cout<<endl;
    return 0;
}
