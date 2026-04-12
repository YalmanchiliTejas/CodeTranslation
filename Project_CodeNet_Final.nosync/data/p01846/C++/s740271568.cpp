#include <bits/stdc++.h>
#define REP(i,n,N) for(int i=n;i<N;i++)
#define p(S) cout<<S<<endl
#define ck(n,a,b) (a<=(n)&&(n)<=b)
using namespace std;

int main(){
	string s;
	int bx,by,nx,ny;
	while(cin>>s>>by>>bx>>ny>>nx&&s!="#"){
		char maps[10][10]={'.'};
		int w,h,y=0,x=0;
		int notb=0;
		vector<char> ans;
		REP(u,0,(int)s.size()){
				if(s[u]=='/'){
					w=x;y++;x=0;
				}else if(s[u]=='b') {
					maps[y][x]='b';x++;
				}
				else x+=s[u]-'0';
		}
		h=y+1;
		maps[ny-1][nx-1]='b';
		maps[by-1][bx-1]='.';
		REP(i,0,h){
			notb=0;
			REP(j,0,w){
				if(maps[i][j]=='b'){
					if(notb>0) cout<<notb;
					cout<<'b';
					notb=0;
				}else 	notb++;
			}
			if(notb>0) cout<<notb;
			if(i==h-1) break;
			cout<<'/';
		}
		p("");
	}
	return 0;
}