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
	ll a[n];
	for(int i=0;i<n;i++){
        cin>>a[i];
	}
	ll mxdp[n][n], mndp[n][n];
	mem(mxdp, 0);
	mem(mndp, 0);
	ll pre[n];
	pre[0] = a[0];
	for(int i=1;i<n;i++){
        pre[i] = pre[i-1] + a[i];
	}
	for(int i=0;i<n;i++){
        mxdp[0][i] = a[i];
	}
	for(int i=1;i<n;i++){
        for(int j=0;j+i<n;j++){
            mxdp[i][j] = max(a[j] + mndp[i-1][j+1], a[i+j] + mndp[i-1][j]);
            mndp[i][j] = pre[j+i] - mxdp[i][j] - (j>0?pre[j-1]:0);
        }
	}
	ll x = mxdp[n-1][0];
	ll y = mndp[n-1][0];
	cout<<x-y;
	return 0;
}
