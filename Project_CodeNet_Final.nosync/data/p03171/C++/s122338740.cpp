#include <bits/stdc++.h>
using namespace std;

#define int        long long
// #define mp      make_pair
#define eb         emplace_back
#define pb         push_back
#define ss         second
#define ff         first
#define IOS        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod        998244353
#define MOD        (1000*1000*1000+7)
#define MN         LLONG_MIN
#define MX         LLONG_MAX
#define v1d        vector<int>
#define v2d        vector<vector<int>>
#define vip        vector<pair<int,int> >
#define v1s        vector<string>
#define pa         pair<int,int>
#define mxpq(T)    priority_queue <T>
#define mnpq(T)    priority_queue<T,vector<T>,greater<T>>
#define print(v)   for(auto i:v)cout<<i<<" ";cout<<"\n";
#define p2d(v)     for(auto a:v){for(auto b:a)cout<<b<<" ";cout<<endl;}
#define p1d(v)     for(auto a:v)cout<<a<<" ";cout<<endl;
#define ppd(v)     for(auto a:v)cout<<a.ff<<" "<<a.ss<<endl;
#define endl       "\n"
#define input(b,n) for(int i=0;i<n;i++)cin>>b[i];
#define Sort(v)    sort(v.begin(),v.end())
#define RSort(v)   sort(v.rbegin(),v.rend())
#define all(v)     v.begin(),v.end()
int gcd(int a,int b){return b?gcd(b,a%b):a;}
//string s = bitset<64>(a).to_string();

void vrikodara(int n=12){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout<<setprecision(n)<<fixed;
    // #ifndef ONLINE_JUDGE
    //      freopen("input.txt",  "r",  stdin);
    //      freopen("output.txt", "w", stdout);
    // #endif
}

//____________________________________________________________________________________

v2d dp(3005,v1d(3005,-1));

int fun(v1d &v,int n,int i,int j){
    if(dp[i][j] != -1)return dp[i][j];
    if(i == j)return dp[i][j] = v[i];
    dp[i][j] = max(v[i]-fun(v,n,i+1,j), v[j]-fun(v,n,i,j-1));
    return dp[i][j];
}

void solve(){
    int n,k;cin>>n;
    v1d v(n+2);
    for(int i=0;i<n;i++)cin>>v[i+1];
    cout<<fun(v,n,1,n);
}

int32_t main(){
    vrikodara();
    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
    


    return 0;
}
