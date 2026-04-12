#include <bits/stdc++.h>
#include <time.h>
#include <stdlib.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define ull unsigned long long
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/__gcd((a),(b))
#define clr(x) x.clear()
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vi>
#define mp make_pair
#define hell 1000000007
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define all(a) a.begin(),a.end()
#define ign cin.ignore();

#define o_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define o_setll tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set

using namespace std;
using namespace __gnu_pbds;

void __print(int x) {cerr << x;}
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
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

string s;
ll k;

ll dp[10][1000];

ll solve(ll cur_non_zero,ll idx){
    if(idx==s.length())
        return 0;
    if(cur_non_zero==k)
        return 0;
    if(dp[cur_non_zero][idx]!=-1)
        return dp[cur_non_zero][idx];
    if(s[idx]!='0'){
        ll res1=(ll)9-(s[idx]-'0');
        ll rem=k-cur_non_zero-1;
        ll mult;
        if(rem==0)
            mult=1;
        else if(rem==1){
            mult=((ll)s.length()-idx-1)*(ll)9;
        }
        else if(rem==2){
            mult=((ll)81*((ll)s.length()-idx-1)*((ll)s.length()-idx-2))/(ll)2;
        }
        else if(rem==3){
            mult=((ll)729*((ll)s.length()-idx-1)*((ll)s.length()-idx-2)*((ll)s.length()-idx-3))/(ll)6;
        }
        ll ret1=res1*mult;
        ll ret2=solve(cur_non_zero+1,idx+1);
        ll ret=ret1+ret2;
        return dp[cur_non_zero][idx]=ret;
    }
    else{
        ll res1=(ll)9-(s[idx]-'0');
        ll rem=k-cur_non_zero-1;
        ll mult;
        if(rem==0)
            mult=1;
        else if(rem==1){
            mult=((ll)s.length()-idx-1)*(ll)9;
        }
        else if(rem==2){
            mult=((ll)81*((ll)s.length()-idx-1)*((ll)s.length()-idx-2))/(ll)2;
        }
        else if(rem==3){
            mult=((ll)729*((ll)s.length()-idx-1)*((ll)s.length()-idx-2)*((ll)s.length()-idx-3))/(ll)6;
        }
        ll ret1=res1*mult;
        ll ret2=solve(cur_non_zero,idx+1);
        ll ret=ret1+ret2;
        return dp[cur_non_zero][idx]=ret;
    }
}

int main()
{
    IOS
    memset(dp,-1,sizeof(dp));
    string str;
    cin>>str;
    bool flag=false;
    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='0'&&flag==false){
            continue;
        }
        if(flag==true||str[i]!='0')
        {
            flag=true;
            s.pb(str[i]);
        }
    }
    cin>>k;
    ll len=s.length();

    ll tot;
    if(k==1){
        tot=len*(ll)9;
    }
    else if(k==2){
        tot=(((ll)81*len)*(len-1))/(ll)2;
    }
    else {
        tot=((ll)729*len*(len-1)*(len-2))/(ll)6;
    }
    cout<<tot-solve(0,0);
    return 0;
}
