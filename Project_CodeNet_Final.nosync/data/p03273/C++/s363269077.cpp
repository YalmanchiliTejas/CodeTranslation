#include<bits/stdc++.h>
#define int long long
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(a) a.size()
#define re return 
#define MP make_pair
#define pb push_back
#define pii pair<int,int>
#define se second
#define fi first
using namespace std;
char c[105][105];
int n,m;
signed main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>c[i][j];
	for(int i=0;i<n;i++){
		bool check=1;
		for(int j=0;j<m;j++) if(c[i][j]=='#') check=0;
		if(check){
			for(int j=0;j<m;j++) c[i][j]='@';
		}
	} 
	for(int j=0;j<m;j++){
		bool check=1;
		for(int i=0;i<n;i++) if(c[i][j]=='#') check=0;
		if(check){
			for(int i=0;i<n;i++) c[i][j]='@';
		}
	}
	for(int i=0;i<n;i++){
		int x=-1;
		for(int j=m-1;j>=0;j--){
			if(c[i][j]!='@'){
				x=j;
				break;
			} 
		}
		for(int j=0;j<m;j++){
			if(c[i][j]=='@') continue;
			cout<<c[i][j];
			if(j==x) cout<<"\n";
		}
	}
	re 0;
}