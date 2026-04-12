#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define rrep(i,n) for(int i=n-1;i>=0;--i)
#define yesno(flg) if(flg){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define MAX_N 1002
#define i197 1000000007

using namespace std;

typedef long long ll;
typedef pair<ll,ll> P1;
typedef pair<int,int> Pi;
typedef pair<double,Pi> Pdi;
typedef pair<ll,int>Pli;
typedef pair<P1,ll> P2;
const ll INF=100000000000000001;
struct edge{int to,cost;};
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};
struct Road{double cost;int a,b;};


int main() {

	int h,w;
	char a[101][101];
	int c[101][101]={};
	int o=0;

	cin>>h>>w;
	rep(i,h){
		rep(j,w){
			cin>>a[j][i];
		}
	}
	rep(i,h){
		o=0;
		rep(j,w){
			if(a[j][i]=='.'){
				o++;
			}
			if(o==w){
				rep(k,w){
					c[k][i]=1;

				}
			}
		}
	}
	rep(j,w){
		o=0;
		rep(i,h){
			if(a[j][i]=='.'){
				o++;
			}
			if(o==h){
				rep(k,h){
					c[j][k]=1;
				}
			}
		}
	}

	int f=0;
	rep(i,h){
		f=0;
		rep(j,w){
			if(c[j][i]==0){
				cout<<a[j][i];
				f=1;
			}
		}
		if(f==1){
			cout<<endl;
		}
	}
	return 0;
}
