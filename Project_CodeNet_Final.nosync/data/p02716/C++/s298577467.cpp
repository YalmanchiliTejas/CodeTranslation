#include <bits/stdc++.h>//Carefully Crafted by hetp111
using namespace std;
#define int long long
#define double long double
#define all(v) (v).begin(),(v).end()
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vii vector<pii>
#define MOD (1000000007)
#define MOD2 (998244353)
#define MOD3 (1000000009)
#define PI acos(-1)
#define eps (1e-8)
#define INF (1e18)
#define FASTER ios_base::sync_with_stdio(0);cin.tie(0)
template<class A,class B>ostream&operator<<(ostream&out,const pair<A,B>&a){return out<<"("<<a.first<<","<<a.second<<")";}
template<class A>ostream&operator<<(ostream&out,const vector<A>&a){for(const A &it:a)out<<it<<" ";return out;}
template<class A,class B>istream&operator>>(istream&in,pair<A,B>&a){return in>>a.first>>a.second;}
template<class A>istream&operator>>(istream&in,vector<A>&a){for(A &i:a)in>>i;return in;}
ifstream cinn("input.txt");ofstream coutt("output.txt");

int a[200005];
int pre[200005];
int dp[200005];

signed main(){
    FASTER;
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pre[i]=a[i];
    }
    for(int i=3;i<=n;i+=2)pre[i]+=pre[i-2];
    
    for(int i=2;i<=n;i++){
        if(i&1){
            dp[i]=max(dp[i-2]+a[i],dp[i-1]);
        }else{
            dp[i]=max(dp[i-2]+a[i],pre[i-1]);
        }
    }
    cout<<dp[n];
    
}