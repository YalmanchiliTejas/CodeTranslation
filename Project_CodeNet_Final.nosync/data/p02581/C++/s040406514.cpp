#include<bits/stdc++.h>
#define ll long long
#define reg register
#define mp make_pair
#define ri register int
using namespace std;
const int mxn=2e5+5;
int a[mxn],n;
int dp[2222][2222];
int base=1e8,mx=1e8,rmx[2222];
inline void cmax(int&a,int b){if(a<b)a=b;}
vector<tuple<int,int,int> >upd;
inline void Upd(int i,int j,int k){
	upd.emplace_back(i,j,k);
	swap(i,j);
	upd.emplace_back(i,j,k);
}
inline void solve(){
	cin>>n;
	for(int i=0;i<3*n;++i)cin>>a[i];
	dp[a[0]][a[1]]=rmx[a[0]]=rmx[a[1]]=base;
	for(int i=2;i<3*n;i+=3){
		if(a[i]==a[i+1] and a[i]==a[i+2]){
			--base;
			continue;
		}
		for(int _=0;_<3;++_){
			swap(a[i],a[i+1]),swap(a[i+1],a[i+2]);
			Upd(a[i],a[i+1],max(mx,dp[a[i+2]][a[i+2]]+1));
			for(int j=1;j<=n;++j){
				if(a[i+1]==a[i+2])Upd(j,a[i],dp[j][a[i+1]]+1);
				Upd(j,a[i],rmx[j]);
			}
		}
		for(int i=0;i<upd.size();++i){
			int e,f,g;
			tie(e,f,g)=upd[i];
			cmax(dp[e][f],g),cmax(rmx[e],g),cmax(mx,g);
		}
		upd.clear();
	}
	cout<<mx-base<<'\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T=1;//cin>>T;
	for(;T--;)solve();
}
