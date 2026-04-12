#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ll,ii>
#define fi first
#define se second
#define endl '\n'
#define debug(x) cout << #x << " is " << x << endl;

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

ll MAX(ll a){return a;}
ll MIN(ll a){return a;}
template<typename... Args>
ll MAX(ll a,Args... args){return max(a,MAX(args...));}
template<typename... Args>
ll MIN(ll a,Args... args){return min(a,MIN(args...));}

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>

#define ull unsigned long long

int n;
int s[505];
int t[505];
ull u[505];
ull v[505];

ull ans[505][505];

ull layer[505][505];

vector<int> row,col;

void rage(){
	cout<<"-1"<<endl;
	exit(0);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	
	rep(x,0,n) cin>>s[x];
	rep(x,0,n) cin>>t[x];
	rep(x,0,n) cin>>u[x];
	rep(x,0,n) cin>>v[x];
	
	//and 0
	//or 1
	
	rep(bit,0,64){
		row.clear();
		col.clear();
	
		memset(layer,-1,sizeof(layer));
		
		rep(x,0,n){
			if (s[x]==0){ //and
				if (u[x]&(1ULL<<bit)) rep(y,0,n){
					if (layer[x][y]==0) rage();
					layer[x][y]=1;
				}
				else{
					row.push_back(x);
				}
			}
			else{
				if ((u[x]&(1ULL<<bit))==0) rep(y,0,n){
					if (layer[x][y]==1) rage();
					layer[x][y]=0;
				}
				else{
					row.push_back(x);
				}
			}
		}
		
		rep(y,0,n){
			if (t[y]==0){ //and
				if (v[y]&(1ULL<<bit)) rep(x,0,n){
					if (layer[x][y]==0) rage();
					layer[x][y]=1;
				}
				else{
					col.push_back(y);
				}
			}
			else{
				if ((v[y]&(1ULL<<bit))==0) rep(x,0,n){
					if (layer[x][y]==1) rage();
					layer[x][y]=0;
				}
				else{
					col.push_back(y);
				}
			}
		}
		
		/*		
		rep(x,0,n){
			rep(y,0,n) cout<<layer[x][y]<<" ";
			cout<<endl;
		}
		*/
		
		//cout<<row.size()<<" "<<col.size()<<endl;
		
		if (row.size()==0 || col.size()==0){
			;
		}
		else if (row.size()==1){
			int bitr=s[row[0]];
			for (auto &it:col){
				int bitc=t[it];
				
				rep(x,0,n){
					if (layer[x][it]==bitc){
						layer[row[0]][it]=bitr;
						break;
					}
				}
				if (layer[row[0]][it]>1){
					layer[row[0]][it]=bitc;
				}
			}
		}
		else if (col.size()==1){
			int bitc=t[col[0]];
			for (auto &it:row){
				int bitr=s[it];
				
				rep(y,0,n){
					if (layer[it][y]==bitr){
						layer[it][col[0]]=bitc;
						break;
					}
				}
				if (layer[it][col[0]]>1){
					layer[it][col[0]]=bitr;
				}
			}
		}
		else{
			rep(x,0,row.size()){
				rep(y,0,col.size()){
					layer[row[x]][col[y]]=((x^y)&1);
				}
			}
		}
		
		/*
		rep(x,0,n){
			rep(y,0,n) cout<<layer[x][y]<<" ";
			cout<<endl;
			
		}
		cout<<endl;
		*/
				
		rep(x,0,n){
			rep(y,0,n){
				ans[x][y]|=(layer[x][y]<<bit);
			}
		}
	}
	
	ull U[505];
	ull V[505];
	
	rep(x,0,n){
		U[x]=ans[x][0];
		rep(y,0,n){
			if (s[x]==0) U[x]&=ans[x][y];
			else U[x]|=ans[x][y];
		}
	}
	rep(y,0,n){
		V[y]=ans[0][y];
		rep(x,0,n){
			if (t[y]==0) V[y]&=ans[x][y];
			else V[y]|=ans[x][y];
		}
	}
	
	rep(x,0,n){
		if (U[x]!=u[x]) rage();
	}
	
	rep(x,0,n){
		if (V[x]!=v[x]) rage();
	}
	
	rep(x,0,n){
		rep(y,0,n){
			cout<<ans[x][y]<<" ";
		}
		
		cout<<endl;
	}
}
