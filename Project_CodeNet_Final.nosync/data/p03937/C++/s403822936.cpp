#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
int H, W;
vector<vector<char>>field;
void dfs(int _i, int _j) {
	vector<int>dxy={0,1,0};
	field[_i][_j]='.';
	if(_i==H-1&&_j==W-1)return;

	for(int i=0; i<2; ++i) {
		int ty=_i+dxy[i], tx=_j+dxy[i+1];
		if(ty>=0&&ty<H&&tx>=0&&tx<W&&field[ty][tx]=='#')
			return dfs(ty, tx);
	}
}
int main() {
	cin>>H>>W;
	field=vector<vector<char>>(H,vector<char>(W));
	for(auto& e:field)
	for(auto& c:e)
		cin>>c;
	
	int cnt=0;
	for(int i=0; i<H; ++i)
	for(int j=0; j<W; ++j){
		if(field[i][j]=='#') {
			dfs(i,j);
			++cnt;
		}
	}

	if(cnt==1)cout<<"Possible";
	else cout<<"Impossible";
	cout<<endl;

	return 0;
}