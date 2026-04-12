#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
 
#define int long long int
#define ld long double
#define mod 1000000007 
#define pii pair<int,int>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define forn(i,s, e) for (int i = s; i <= e; i++)
#define fornd(i,s, e) for (int i = s ; i >= e; i--)
#define autoit(x,it) for(auto it = x.begin(); it != x.end(); it++)
#define print(x) for(auto el: x) cout<<el<<" ";cout<<"\n"
#define PSET(x,y) fixed<<setprecision(y)<<x
// #define bits(x) __builtin_popcount(x)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
// void fileio()
// {
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
// }
 
 
template <typename T> 
void swap(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}
void selfadd(int& a, int b){
    a = a+b;
    if(a>=mod)
        a = a-mod;
}
void selfsub(int& a, int b){
    a = a-b+mod;
    if(a>=mod)
        a = a-mod;
}  
const int N = 200005; 
 
int dp[10002][103][2];
int D;
 
int rec(string& s, int index,int d, int state){
    
    if(index==s.size()){
        if(d==0)
            return 1;
        else
            return 0;
    }
    if(dp[index][d][state] !=-1){
        return dp[index][d][state];
    }
 
    int a = s[index]-'0';
 
    int ans = 0;
    if(state){
        for(int i=0;i<a;i++){
            selfadd(ans ,rec(s,index+1,(d+i)%D, 0)); 
        }
        selfadd(ans ,rec(s,index+1,(d+a)%D,1));
    }
    else{
        for(int i=0;i<=9;i++){
            selfadd(ans ,rec(s,index+1,(d+i)%D, 0)); 
        }
    }
    // cout<<index<<" "<<d<<" "<<state<<" "<<ans<<endl;
    return dp[index][d][state] = ans;
 
}
 
void solve(){
    
    string s;
    // int D;
    cin>>s;
    cin>>D;
    memset(dp,-1,sizeof(dp));
    cout<<(rec(s,0,0,1)-1+mod)%mod;
}
 
int32_t main()
{
    // fileio();
    fast;
    // int t;
    // cin>>t;
    // for(int y=1;y<=t;y++)
    {
        // cout<<"Case #"<<y<<": ";
        solve();
    }
    return 0;
} 