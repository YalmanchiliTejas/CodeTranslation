#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(void){
	int H,W;
	bool res=true;
	cin>>H>>W;
	string s[H];
	rep(y,H)cin>>s[y];
	int X=0,Y=0;
	while(1){
		s[Y][X]='.';
		if(Y<H-1 && s[Y+1][X]=='#')Y++;
		else if(X<W-1 && s[Y][X+1]=='#')X++;
		else break;
	}
	rep(y,H)rep(x,W)res &= s[y][x]=='.';
	cout<<(res ? "Possible" : "Impossible")<<endl;
	return 0;
}
