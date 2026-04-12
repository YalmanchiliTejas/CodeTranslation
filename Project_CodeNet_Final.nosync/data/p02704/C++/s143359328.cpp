#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<n;i++)
using namespace std;
typedef pair<int,int>P;
typedef unsigned long long ll;

const int MOD=1000000007;
//~ const int MOD=998244353;
const int INF=0x3f3f3f3f;
const ll INFL=0x3f3f3f3f3f3f3f3f;

int n;
ll s[600],t[600],u[600],v[600];
ll a[600][600];
int c[64][600][600];

bool check(){
	rep(i,n){
		ll x=a[i][0],y=a[i][0];
		rep(j,n){
			x&=a[i][j];
			y|=a[i][j];
		}
		if(s[i]==0&&x!=u[i])return false;
		if(s[i]==1&&y!=u[i])return false;
	}
	rep(i,n){
		ll x=a[0][i],y=a[0][i];
		rep(j,n){
			x&=a[j][i];
			y|=a[j][i];
		}
		if(t[i]==0&&x!=v[i])return false;
		if(t[i]==1&&y!=v[i])return false;
	}
	return true;
}

int main(){
	cin>>n;
	rep(i,n)cin>>s[i];
	rep(i,n)cin>>t[i];
	rep(i,n)cin>>u[i];
	rep(i,n)cin>>v[i];
	if(n==1){
		a[0][0]=u[0];
		if(!check()){
			puts("-1");return 0;
		}
		cout<<a[0][0]<<endl;
	}
	memset(c,-1,sizeof(c));
	for(int b=0;b<=63;b++){
		int used[4]{};
		rep(i,n){
			if(s[i]==0&&(u[i]>>b&1)==1){
				used[0]=true;
				rep(j,n)c[b][i][j]=1;
			}
			if(s[i]==1&&(u[i]>>b&1)==0){
				used[1]=true;
				rep(j,n)c[b][i][j]=0;
			}
			if(t[i]==0&&(v[i]>>b&1)==1){
				used[2]=true;
				rep(j,n)c[b][j][i]=1;
			}
			if(t[i]==1&&(v[i]>>b&1)==0){
				used[3]=true;
				rep(j,n)c[b][j][i]=0;
			}
		}
		if((used[0]&&used[3])||(used[1]&&used[2])){
			puts("-1");return 0;
		}
		if(!(used[0]||used[1]||used[2]||used[3])){
			rep(i,n)rep(j,n){
				c[b][i][j]=(i+j)%2;
			}
			continue;
		}
		if(used[0]&&used[2]){
			rep(i,n)rep(j,n){
				if(c[b][i][j]==-1)c[b][i][j]=0;
			}
			continue;
		}
		if(used[1]&&used[3]){
			rep(i,n)rep(j,n){
				if(c[b][i][j]==-1)c[b][i][j]=1;
			}
			continue;
		}
		if(used[0]&&used[1]){
			rep(i,n){
				if(!(u[i]>>b&1)){
					rep(j,n){if(c[b][i][j]==-1)c[b][i][j]=0;}
				}
				if(u[i]>>b&1){
					rep(j,n){if(c[b][i][j]==-1)c[b][i][j]=1;}
				}
			}
			continue;
		}
		if(used[2]&&used[3]){
			rep(i,n){
				if(!(v[i]>>b&1)){
					rep(j,n){if(c[b][j][i]==-1)c[b][j][i]=0;}
				}
				if((v[i]>>b&1)){
					rep(j,n){if(c[b][j][i]==-1)c[b][j][i]=1;}
				}
			}
			continue;
		}
		assert(count(used,used+4,true)==1);
		if(used[0]){
			set<int>x,y;
			set<int>x2;
			rep(i,n){
				if(s[i]==1&&(u[i]>>b&1)==1){
					x.insert(i);
				}
				if(!(s[i]==0&&(u[i]>>b&1)==1))x2.insert(i);
				if(t[i]==0&&(v[i]>>b&1)==0){
					y.insert(i);
				}
			}
			if(x.size()==x2.size()&&x.size()==1){
				if(y.size()==n){
					puts("-1");return 0;
				}
				rep(i,n){
					if(!y.count(i)){c[b][*x.begin()][i]=1;break;}
				}
			}
			else{
				int cnt=0;
				for(int i:x){
					c[b][i][cnt]=1;
					cnt=!cnt;
				}
			}
			rep(i,n)rep(j,n){
				if(c[b][i][j]==-1)c[b][i][j]=0;
			}
			continue;
		}
		if(used[1]){
			set<int>x,y;
			set<int>x2;
			rep(i,n){
				if(s[i]==0&&(u[i]>>b&1)==0){
					x.insert(i);
				}
				if(!(s[i]==1&&(u[i]>>b&1)==0))x2.insert(i);
				if(t[i]==1&&(v[i]>>b&1)==1){
					y.insert(i);
				}
			}
			if(x.size()==x2.size()&&x.size()==1){
				if(y.size()==n){
					puts("-1");return 0;
				}
				rep(i,n){
					if(!y.count(i)){c[b][*x.begin()][i]=0;break;}
				}
			}
			else{
				int cnt=0;
				for(int i:x){
					c[b][i][cnt]=0;
					cnt=!cnt;
				}
			}
			rep(i,n)rep(j,n){
				if(c[b][i][j]==-1)c[b][i][j]=1;
			}
			continue;
		}
		if(used[2]){
			set<int>x,y;
			set<int>x2;
			rep(i,n){
				if(t[i]==1&&(v[i]>>b&1)==1){
					x.insert(i);
				}
				if(!(t[i]==0&&(v[i]>>b&1)==1))x2.insert(i);
				if(s[i]==0&&(u[i]>>b&1)==0){
					y.insert(i);
				}
			}
			if(x.size()==x2.size()&&x.size()==1){
				if(y.size()==n){
					puts("-1");return 0;
				}
				rep(i,n){
					if(!y.count(i)){c[b][i][*x.begin()]=1;break;}
				}
			}
			else{
				int cnt=0;
				for(int i:x){
					c[b][cnt][i]=1;
					cnt=!cnt;
				}
			}
			rep(i,n)rep(j,n){
				if(c[b][i][j]==-1)c[b][i][j]=0;
			}
			continue;
		}
		if(used[3]){
			set<int>x,y;
			set<int>x2;
			rep(i,n){
				if(t[i]==0&&(v[i]>>b&1)==0){
					x.insert(i);
				}
				if(!(t[i]==1&&(v[i]>>b&1)==0))x2.insert(i);
				if(s[i]==1&&(u[i]>>b&1)==1){
					y.insert(i);
				}
			}
			if(x.size()==x2.size()&&x.size()==1){
				if(y.size()==n){
					puts("-1");return 0;
				}
				rep(i,n){
					if(!y.count(i)){c[b][i][*x.begin()]=0;break;}
				}
			}
			else{
				int cnt=0;
				for(int i:x){
					c[b][cnt][i]=0;
					cnt=!cnt;
				}
			}
			rep(i,n)rep(j,n){
				if(c[b][i][j]==-1)c[b][i][j]=1;
			}
			continue;
		}
	}
	for(int b=0;b<=63;b++){
		rep(i,n)rep(j,n){
			//~ if(c[b][i][j]==-1){
				//~ abort();
			//~ }
			a[i][j]|=ll(c[b][i][j])<<b;
		}
	}
	if(!check()){
		puts("-1");return 0;
	}
	rep(i,n){
		rep(j,n)cout<<a[i][j]<<' ';
		cout<<endl;
	}
}