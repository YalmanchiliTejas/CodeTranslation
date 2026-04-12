#include<bits/stdc++.h>
#define MOD (1e9 + 7)
#define fi(i,a,b) for(int i = a; i < b; i++)
#define fd(i,a,b) for(int i = a; i >= b; i--)
#define vfi(v,i) for(auto i = v.begin(); i != v.end(); i++)
#define vfd(v,i) for(auto i = v.rbegin(); i != v.rend(); i++)
#define vi vector<int>
#define vll vector<ll>
#define pb push_back 

using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin>>n;
	ll a[n];
	fi(i,0,n){
		cin>>a[i];
	}	
	ll dp[n][n];

	fd(i,n-1,0){
		fi(j,i,n){
			if(i == j){
				dp[i][j] = a[i];
				continue;
			}

			dp[i][j] = max(a[i] - dp[i+1][j], a[j] - dp[i][j-1]);
		}
	}

	cout<<dp[0][n-1]<<'\n';

	return 0;
}