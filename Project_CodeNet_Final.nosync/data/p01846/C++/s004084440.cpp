#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const int INF=INT_MAX,MOD=1e9+7;

int main(){
	string s;
	while(cin>>s&&s!="#"){
		//board:ball=1,null=0
		int board[10][10]; rep(i,10)rep(j,10) board[i][j]=0;
		//getinfo
		int nowY=0,nowX=0,h=1,w=0,tmpw=0;
		for(int i=0;i<(int)s.size();i++){
			if(s[i]=='b'){
				board[nowY][nowX]=1;
				nowX++;
				tmpw++;
			}else if('1'<=s[i]&&s[i]<='9'){
				nowX+=s[i]-'0';
				tmpw+=s[i]-'0';
			}else if(s[i]=='/'){
				nowY++; nowX=0;
				if(!w) w=tmpw;
				h++;
			}
		}
		//rep(i,h)rep(j,w) cout<<board[i][j];
		//swap
		int a,b,c,d; cin>>a>>b>>c>>d;
		a--; b--; c--; d--;
		board[a][b]=0; board[c][d]=1;
		//rep(i,h)rep(j,w) cout<<board[i][j];
		//print
		int cnt=0;
		for(int y=0;y<h;y++){
			for(int x=0;x<w;x++){
				if(board[y][x]){
					if(cnt) cout<<cnt;
					cnt=0;
					cout<<"b";
				}else{
					cnt++;
				}
			}
			if(cnt) cout<<cnt;
			cnt=0;
			if(y!=h-1) cout<<"/";
		}
		cout<<endl;
	}
	return 0;
}

