#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll unsigned long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
ll ans[505][505];
int n;
bool f[2][505],p[64][2][505];
void out(){
	cout<<-1;exit(0);
}
void solve(int now){
	int a[505][505];bool cnt[2][505]={};
	V<int> v[2];
	FILL(a,-1);
	FOR(i,1,n){
		if(p[now][1][i]){
			if(f[1][i])v[1].PB(i);
			else FOR(j,1,n)a[j][i]=1;
		}else{
			if(!f[1][i])v[0].PB(i);
			else FOR(j,1,n)a[j][i]=0;
		}
	}
	bool anf;
	int last[2]={};
	FOR(i,1,n){
		if(p[now][0][i]){
			if(f[0][i]){
				anf=1;
				FOR(j,1,n){
					if(a[i][j]==1){
						anf=0;break;
					}
				}
				if(anf){
					if(!v[1].empty())a[i][v[1].back()]=1;
					else if(!v[0].empty()){
						a[i][v[0][last[0]]]=1;
						last[0]++;
						if(last[0]==v[0].size())last[0]=0;
					}else out();
				}
			}else{
				FOR(j,1,n){
					if(a[i][j]==0)out();
					a[i][j]=1;
				}
			}
		}else{
			if(!f[0][i]){
				anf=1;
				FOR(j,1,n){
					if(a[i][j]==0){
						anf=0;break;
					}
				}
				if(anf){
					if(!v[0].empty())a[i][v[0].back()]=0;
					else if(!v[1].empty()){
						a[i][v[1][last[1]]]=0;
						last[1]++;
						if(last[1]==v[1].size())last[1]=0;
					}else out();
				}
			}else{
				FOR(j,1,n){
					if(a[i][j]==1)out();
					a[i][j]=0;
				}
			}
		}
	}
	FOR(k,0,1){
	for(auto u:v[k]){
		FOR(i,1,n){
			if(a[i][u]==-1)a[i][u]=k;
		}
		bool anf=0;
		FOR(i,1,n){
			if(a[i][u]==k){
				anf=1;break;
			}
		}
		if(!anf)out();
	}
	}
	FOR(i,1,n)FOR(j,1,n)ans[i][j]=ans[i][j]+(1ull<<now)*a[i][j];
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,1,n)cin>>f[0][i];
	FOR(i,1,n)cin>>f[1][i];
	ll x,t;
	FOR(i,1,n){
		cin>>x;
		FOR(j,0,63){
			if(!j)t=1;
			else t=t*2;
			if(x&t)p[j][0][i]=1;
		}
	}
	FOR(i,1,n){
		cin>>x;
		FOR(j,0,63){
			if(!j)t=1;
			else t=t*2;
			if(x&t)p[j][1][i]=1;
		}
	}
	FOR(i,0,63)solve(i);
	FOR(i,1,n){
		FOR(j,1,n)cout<<ans[i][j]<<' ';
		cout<<'\n';
	}
	RE 0;
}


