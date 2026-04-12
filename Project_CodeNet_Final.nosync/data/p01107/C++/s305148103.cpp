#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> mp;
#define inf 1e9
int dx[] = { 1 ,0,-1,0};
int dy[] = { 0, 1,0,-1};

int n,m;
bool dfs(int x,int y,vector<vector<bool> > &used,int d, int cnt){
 //   cout<<x<<' '<<y<<endl;
    if( x== 1 && y == 1 &&cnt==3) return true;
    //if( !used[x][y] )return  false;
    //used[x][y] = false;
    if( x== 1 && y== m ) cnt++;
    if( x== n && y== 1 ) cnt++;
    if( x== n && y== m ) cnt++;
    //if( cnt == 3 ) return true;
    for(int i=0;i<4;i++){
    	int nd =  ( d + 3 + i) % 4;
    	int nx = x + dx[nd];
    	int ny = y + dy[nd];
    	//if( nx == 1 && ny == 1 && cnt == 3) return true;
    	if(used[nx][ny]){
	    used[nx][ny] = false;
	    if( dfs(nx,ny,used,nd,cnt) ) return true;
    	}
    }
    return false;
}

int main(){
    while(1){
	cin>>n>>m;
	if(n==0)break;
	vector<vector<bool> > used(n+2,vector<bool>(m+2,false) );
	for(int i=1;i<=n;i++){
	    for(int j=1;j<=m;j++){
		char tmp;
		cin>>tmp;
		if(tmp=='.'){
		    used[i][j] = true;
		}
	    }
    	}
	if(dfs(1,1,used,0,0) ) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
    }
    return 0;
}

