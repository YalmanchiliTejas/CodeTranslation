#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main(){

	int a, b, flag;
	char tmp;
	vector< vector<int> > board;

	cin>> a >> b;
	board.resize(a);
	for(int i=0;i<a;i++) board[i].resize(b);

	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			cin>> tmp;
			if(tmp=='#') board[i][j]=1;
			else board[i][j]=0;
		}
	}

	for(int i=0;i<b;i++){
		flag=1;
		for(int j=0;j<a;j++){
			if(board[j][i]==1) flag=0;
		}
		if(flag){
			for(int j=0;j<a;j++) board[j].erase(board[j].begin() + i);
			i--;
			b--;
		}
	}

	for(int i=0;i<a;i++){
		flag=1;
		for(int j=0;j<b;j++){
			if(board[i][j]==1) flag=0;
		}
		if(flag){
			board.erase(board.begin() + i);
			i--;
			a--;
		}
	}

	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			if(board[i][j]==1) cout<< '#';
			else cout<< '.';
		}
		cout<< endl;
	}

}