#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace __gnu_pbds;
using namespace std;
/*
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
*/
#define ull unsigned long long int
#define ll long long int
#define ld long double
#define MAX 1000000007
//1e9+7
#define pll pair<ll,ll>
#define pii pair<int,int>
#define piii pair<int,pii>
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define FO ifstream fin("a.in");ofstream fout("a.out");
#define TEST int testcase;cin>>testcase;while(testcase--)
#define FTEST int testcase;fin>>testcase;while(testcase--)
#define all(x) (x).begin(),(x).end()
#define mset0(x) memset((x), 0, sizeof((x)));
#define mset1(x) memset((x), -1, sizeof((x)));
#define endl "\n"
#define plll pair<ll,pll>
#define plii pair<ll,pii>
#define no {cout<<"no"<<endl;return;}
#define yes {cout<<"yes"<<endl;}
#define rep(i,N) for(int i=0;i<N;i++)
const int maxn=3e5;
const int mod=998244353;
typedef tree<ll,null_type,less<ll>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
ull power(ull a,ll b){
    ull ans=1;
    while(b){
        if(b&1) ans=ans*a;
        b/=2;
        a=a*a;
    }
    return(ans);
}
ll arr[maxn+1];
ll dp[maxn+1];
vector<int> v;
void solve(){
    int n,a;cin>>n;
    dp[0]=0;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        dp[i]=(dp[i-1]+arr[i])%MAX;
    }
    ll sum=0;
    for(int i=2;i<=n;i++){
        sum=(sum+arr[i]*dp[i-1])%MAX;
    }
    cout<<sum;
    return;
}
int main(){
    IO
    //TEST
    solve();
    return(0);
}
/*
2
3 3
2500 2500 2520
10 -5 -20
10 15 20
-15 17 13
2 3
2125 2098
-20 10 -10
10 10 -20
*/
/*
1
3 3
2500 2500 2520
10 -5 -20
10 15 20
-15 17 13

*/
