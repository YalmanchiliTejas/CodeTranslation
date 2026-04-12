#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = 1; i <= n; i++)
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a,b); }
using P = pair <int, int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
 
ll MOD = 1000000007;
ll INF =1<<30;
ll dp[110][100100];
 
 
int main(){
    int n;
    cin >>n;
    vector<int>a(n);
    rep(i,n)cin >> a[i];
    deque<int>deq;
    rep(i,n){
         if(i%2==0)deq.push_back(a[i]);
         else deq.push_front(a[i]);
    }
    vector<int>ans;
    for(auto x:deq) ans.push_back(x);
    if(n%2!=0){
         reverse(ans.begin(),ans.end());
         rep(i,ans.size()) cout<<ans[i]<<' ';
    }
    else{
         rep(i,ans.size()) cout << ans[i]<<' ';
    }
}