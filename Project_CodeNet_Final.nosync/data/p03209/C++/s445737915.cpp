#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);++i)

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n,x;cin >> n >> x;
	vector<ll> ban(n+1);
	vector<ll> sou(n+1);
	ban[0]=1;
	sou[0]=1;
	rep(i,n){
		ban[i+1]=ban[i]*2+1;
		sou[i+1]=sou[i]*2+3;
	}
	ll ans=0;
	for(int i=n;i>=0;--i){
		if(i==0){
			ans++;
			break;
		}
		if(x==1) break;
		if(x==sou[i]){
			ans+=ban[i];
			break;
		}
		if(sou[i-1]+2==x){
			ans+=ban[i-1]+1;
			break;
		}
		else if(sou[i-1]+2>x){
			x--;
		}
		else{
			ans+=ban[i-1]+1;
			x-=sou[i-1]+2;
		}
	}
	cout << ans << endl;
}