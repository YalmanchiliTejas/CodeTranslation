#include<bits/stdc++.h>
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define ggr getchar(); getchar();return 0;
using namespace std;
typedef pair<ll, ll>P;
ll n,m,ans=0;
ll a[30],b[30];
int c[9];
bool f[9][9];
signed main() {
	cin>>n>>m;
	rep(i,m){
		cin>>a[i]>>b[i];
		f[a[i]][b[i]]=true;
		f[b[i]][a[i]]=true;
	}
	rep(i,n)c[i]=i+1;
	do{
		bool ok=true;
		for(int i=1;i<n;i++){
			if(!f[c[i-1]][c[i]])ok=false;
		}
		if(ok)ans++;
	}while(next_permutation(c+1,c+n));
	cout<<ans<<endl;
	ggr
}


