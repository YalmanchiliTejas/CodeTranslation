//T2
#include<iostream>
#include<string>
using namespace std;
const int N=102;
string mat[N];
int flag[N][N];
int main(){
	ios::sync_with_stdio(false);
	int n,m; cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>mat[i]; bool ok=1;
		for(int j=0;j<m;j++){
			if(mat[i][j]=='#'){ok=0; break;}
		}
		if(ok){
			for(int j=0;j<m;j++) flag[i][j]=1;
		}
	}
	for(int j=0;j<m;j++){
		bool ok=1;
		for(int i=0;i<n;i++){
			if(mat[i][j]=='#'){ok=0; break;}
		}
		if(ok){
			for(int i=0;i<n;i++) flag[i][j]=1;
		}
	}
	for(int i=0;i<n;i++){
		bool ok=1;
		for(int j=0;j<m;j++){
			if(!flag[i][j]){ok=0; cout<<mat[i][j];}
		}
		if(!ok) cout<<endl;
	}
return 0;
}