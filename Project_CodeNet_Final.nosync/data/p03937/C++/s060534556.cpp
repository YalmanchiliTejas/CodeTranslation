#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define yesno(flg) if(flg){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}
#define MAX_N 10
using namespace std;

typedef long long ll;
typedef pair<int,int> P1;
typedef pair<P1,P1> P2;
const ll INF=100000000000000001;
int dp[MAX_N][MAX_N]={};
bool d[MAX_N]={};
struct edge{int to,cost;};
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};
queue<P1> que;
vector<string> v;
int main() {
	int h,w;
	cin>>h>>w;
	rep(i,h){
		rep(j,w){
			char chr;
			cin>>chr;
			if(chr=='#')dp[i][j]=1;
		}
	}
	que.push(P1(0,0));
	while(!que.empty()){
		P1 pp1=que.front();que.pop();
		int x=pp1.first;
		int y= pp1.second;
		dp[x][y]=2;
		if(dp[x+1][y]==1&&dp[x][y+1]==1){
			cout<<"Impossible"<<endl;
			return 0;
		}
		if(dp[x+1][y]==1)que.push(P1(x+1,y));
		if(dp[x][y+1]==1)que.push(P1(x,y+1));
	}
	bool flg=true;
	rep(i,h){
		rep(j,w){
			if(dp[i][j]==1)flg=false;
		}
	}
	if(flg){
		cout<<"Possible"<<endl;
	}else{
		cout<<"Impossible"<<endl;
	}
	return 0;
}
