#include <bits/stdc++.h>
#define REP(i,n,N) for(int i=n;i<N;i++)
#define p(S) cout<<(S)<<endl
#define ck(n,a,b) (a<=(n)&&(n)<b)
using namespace std;

int main(){
	int H,W;
	int dx[2]={1,0};
	int dy[2]={0,1};
	cin>>H>>W;
	char A[9][9];
	int ansc=0;
	REP(i,0,H) REP(j,0,W) {
		cin>>A[i][j];
		if(A[i][j]=='#') ansc++;
	}
	stack<pair<int,int>> st;
	stack<int> cnt;
	st.push({0,0});
	cnt.push(1);
	bool flag=false;
	while(!st.empty()){
		int x=st.top().first,y=st.top().second;
		int c=cnt.top();
		cnt.pop();
		st.pop();
		if(x==W-1&&y==H-1) {
			if(ansc==c){
				flag=true;
				break;
			}
		}
		REP(i,0,2){
			int nx=x+dx[i],ny=y+dy[i];
			if(!ck(nx,0,W)||!ck(ny,0,H)) continue;
			if(A[ny][nx]=='#'){
				st.push({nx,ny});
				cnt.push(c+1);
			}
		}
	}
	p(flag?"Possible":"Impossible");
	return 0;
}
