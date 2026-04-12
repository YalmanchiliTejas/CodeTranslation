#include "bits/stdc++.h"
#define REP(i,n,N) for(ll i=n; i<N; i++)
#define p(s) cout<<(s)<<endl
#define p2(a, b) cout<<(a)<<" "<<(b)<<endl
using namespace std;
typedef long long ll;

int main() {
	string s;
	int a,b,c,d;
	vector<vector<char>> board(10,vector<char>(10));
	while(1){
		cin >> s;
		if(s[0]=='#')break;
		cin >> a >> b >> c >> d;
		REP(i,0,10)REP(j,0,10) board[i][j]='?';
		int column=0;
		int row=0;

		//board作成
		REP(i,0,s.size()){
			if(s[i]=='/'){
				column++;
				row=0;
				continue;
			}
			if(s[i]=='b'){
				board[column][row]='b';
				row++;
				continue;
			}
			int num=(s[i]-'0');
			REP(j,0,num){
				board[column][row] = '.';
				row++;
			}
		}

		board[a-1][b-1]='.';
		board[c-1][d-1]='b';

		string ans;
		REP(i,0,10){
			if(board[i][0]=='?') break;
			int count=0;
			REP(j,0,10){
				if(board[i][j]=='?'){
					if(count!=0) ans.push_back(count+'0');
					ans.push_back('/');
					count=0;
					break;
				}
				if(board[i][j]=='.'){
					count++;
					continue;
				}
				if(board[i][j]=='b'){
					if(count!=0) ans.push_back(count+'0');
					ans.push_back('b');
					count=0;
				}
			}
		}
		if(ans.back()=='/')ans.pop_back();
		p(ans);

	}
	return 0;
}

