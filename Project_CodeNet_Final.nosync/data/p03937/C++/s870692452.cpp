#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define until(x) while(!(x))
#define unless(x) if(!(x))
#define all(x) (x).begin(),(x).end()

char grid[10][10];
bool done[10][10];
int32_t main(){
	int h,w;
	cin>>h>>w;
	for(int i=1;i<=h;i++){
		cin>>grid[i]+1;
	}
	int curx = 1;
	int cury = 1;
	if(grid[1][1]=='.'){
		cout<<"Impossible";
		return 0;
	}
	until(curx==w && cury==h){
		done[cury][curx]=1;
		int p = grid[cury+1][curx]=='#';
		int q = grid[cury][curx+1]=='#';
		if(p&&q){
			cout<<"Impossible";
			return 0;
		}
		if(p){
			cury++;
		}
		if(q){
			curx++;
		}
		if(!(p+q)){
			cout<<"Impossible";
			return 0;
		}
		done[cury][curx]=1;
	}
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			if(!done[i][j] && grid[i][j]=='#'){
				cout<<"Impossible";
				return 0;
			}
		}
	}
	cout<<"Possible";
}
