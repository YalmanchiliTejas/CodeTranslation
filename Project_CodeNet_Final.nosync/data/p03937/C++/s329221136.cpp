#include<bits/stdc++.h>
int a[10][10];
int n,m;
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	int total=0;
	
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		for(int j=1;j<=m;j++){
			if(s[j-1]=='#') {
				a[i][j]=1;
				total++;
			}
		}
	}
	if(!a[1][1]){
		cout<<"Impossible";
		return 0;
	}
	int x=1,y=1;
	int cnt=1;
	while(1){
		if(x==n&&y==m){
			if(cnt==total){
				cout<<"Possible";
				return 0;
			}
			cout<<"Impossible";
			return 0;
		}
		if(!(a[x+1][y]^a[x][y+1])){
		
			cout<<"Impossible";
			return 0;
		}
		if(a[x+1][y]){
			x++;
			cnt++;
			continue;
		}
		else{
			y++;
			cnt++;
		}
	}
}
