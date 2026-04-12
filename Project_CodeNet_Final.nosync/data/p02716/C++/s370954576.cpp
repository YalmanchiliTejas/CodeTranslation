#include<bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii>
#define vll vector<pll>
#define all(v) v.begin(),v.end()
#define mem(v,x) memset(v,x,sizeof(v))
#define N 100005

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
    int n;
    cin>>n;
    ll a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    ll pre[n+1]={0};
    ll dp[n+1]={0};
    pre[1] = a[1];
    for(int i=2;i<=n;i++){
        if(i&1){
            pre[i] = pre[i-2]+a[i];
            dp[i] = max(a[i]+dp[i-2], dp[i-1]);
        }
        else{
            pre[i] = pre[i-2]+a[i];
            dp[i] = max(a[i]+dp[i-2],pre[i-1]);
        }
    }
    cout<<dp[n];
	return 0;
}
