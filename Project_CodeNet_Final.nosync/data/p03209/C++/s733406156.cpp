using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i = 0; i < (n); i++)
#define divup(a,b) ( ( (a) + ( (b) - 1u) ) / (b) ) // a/b の余り切り上げ
// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
ll mod = 1000000007;

ll n,x,ans,kai;
ll s[53];
ll p[53];
ll solve(ll x,ll n,ll ans){
    if(x==1){
        if (n==0) return ans+1; 
        else return ans;
    }else if(x==s[n]){
        return ans + p[n];
    }else if(x==((s[n]+1)/2)){
        return ans + p[n-1]+1;
    }else if(x<((s[n]+1)/2)){
        solve(x-1,n-1,ans);
    }else{
        solve(x-((s[n]+1)/2),n-1,ans+1+p[n-1]);
    }
}
signed main(){
    cin>>n>>x;
    rep(i,n+1){
        if(i==0){
            s[i]=1;
            p[i]=1;
        }else{
            s[i]=3+s[i-1]*2;
            p[i]=1+p[i-1]*2;
        }
    }
    kai = solve(x,n,0);
    cout<<kai<<endl;
}
