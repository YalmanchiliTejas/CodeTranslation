#include "bits/stdc++.h"
#pragma GCC optimize("Ofast")

#pragma GCC target("avx,avx2")
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ll=long long ;
#define Whats(x)// cout<<#x<<" is "<<(x)<<endl

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int memo[52][52][4][8];

int H, W;
bool ok=false;
bool dfs(int x, int y, const vector<string>&field, vector<vector<int>>&comes,int way,int flag) {
	if(memo[x][y][way][flag]!=-1)return false;
	else memo[x][y][way][flag]=0;
	if(y!=H||x!=1)comes[y][x]=true;

	if(x==1&&y==1)flag^=1;
	if(x==W&&y==1)flag^=2;
	if(x==W&&y==H)flag^=4;
	if (x == 1 && y == H && flag == 7) {
		ok=true;
		throw(false);
	}
	Whats(x);
	Whats(y);
	for (int nway = way - 1; nway <= way + 1; ++nway) {
		int away=(nway+4)%4;
		int nx=x+dx[away];
		int ny=y+dy[away];
		
		if (field[ny][nx] == '.'&&comes[ny][nx]==false) {
			dfs(nx,ny,field,comes,away,flag);
		}
	}
	comes[y][x]=false;
	return false;
}

int main() {
	while (true) {
		cin>>H>>W;
		if(!H)break;
		ok=false;
		for (int i = 0; i < 52; ++i) {
			for (int j = 0; j < 52; ++j) {
				for (int way = 0; way < 4; ++way) {
					for (int x = 0; x < 8; ++x) {
						memo[i][j][way][x]=-1;
					}
				}
			}
		}
		vector<string>field(H+2);
		field[0]=string(W+2,'#');
		field[H+1]=string(W+2,'#');
		for (int i = 0; i < H; ++i) {
			string st; cin >> st;
			st.insert(st.begin(), '#');
			st.insert(st.end(), '#');
			field[i + 1] = st;
		}

		vector<vector<int>>comes(H+2,vector<int>(W+2));
		try {
			dfs(1,H,field,comes,2,0);
		}
		catch (...) {
		}
		if (ok) {
			cout<<"YES"<<endl;

		}
		else {
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
