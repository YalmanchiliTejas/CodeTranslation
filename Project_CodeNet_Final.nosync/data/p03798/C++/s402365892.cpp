/*
 * Author: .-O_O-.
 */
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include<bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define pb push_back
#define vi vector<int>
#define rep0(a,b) for(int a=0;a<b;a++)
#define rep1(a,b) for(int a=1;a<=b;a++)
#define repp(a,b,c) for(int a=b;a<c;a++)
#define in insert
#define len length()
#define si size()
#define lb lower_bound
#define ub upper_bound
#define beg begin()
#define en end()
#define f first
#define s second
#define pr(a) cout<<a
#define pr2(a,b) cout<<a<<" "<<b<<"\n"
#define nx cout<<"\n"
#define int long long
// void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
                                                     
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]"<<endl;}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define deb(x...)
#endif
const ll mod = 1000000007;
const ll N = 105;
const ll mm = 1e+18;
bool chk1(char c,char cu,char c1,char c2){
    //deb(c,cu,c1,c2);
    if(cu=='S'){
        return ((c1==c2&&c=='o')||(c1!=c2&&c=='x'));
    }
    else{
        return ((c1==c2&&c=='x')||(c1!=c2&&c=='o'));
    }
}
bool chk(string s,string ans,int n){
    //deb(s,ans,n);
    rep0(i,n){
        if(!chk1(s[i],ans[i],ans[(i-1+n)%n],ans[(i+1)%n])) return false;
    }
    return true;
}
char fii(char c,char cu,char c1){
    if(cu=='S'){
        if(c=='o'){
            return c1;
        }
        else{
            if(c1=='S') return 'W';
            else return 'S';
        }
    }
    else{
        if(c=='o'){
            if(c1=='S') return 'W';
            else return 'S';
        }
        else return c1;
    }
}
void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    char c[]={'S','W'};
    rep0(i,2){
        rep0(j,2){
            string ans="";
            ans+=c[i];
            ans+=c[j];
            repp(i,2,n){
                ans+=fii(s[i-1],ans[i-1],ans[i-2]);
            }
            if(chk(s,ans,n)){
                cout<<ans;
                return;
            }
        }
    }
    cout<<-1;
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    //cin>>t;
    rep1(_i,t){
        //cout<<"Case #"<<_i<<": ";
        solve();
        //nx;
    }
    return 0;
}