#include <bits/stdc++.h>

using namespace std;

#define lli long long int
#define REP(i,s,n) for(lli i=s;i<n;i++)
#define RREP(i,s,n) for(lli i=s;i>=n;i--)
#define MOD 1000000007
#define NUM 2520
#define DEBUG 0
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())
#define PI (3.141592653589794)
#define INF (1LL<<50)

lli data[10][10];
lli flag[10][10];

signed main(){

	lli h,w;
	cin>>h>>w;

	REP(i,0,h)REP(j,0,w){
		char tmp;
		cin>>tmp;
		if(tmp=='#')data[i][j]=1;
	}

	queue<pair<lli,lli>> q;
	q.push(mp(0,0));
	flag[0][0]=1;

	while(q.size()){
		pair<lli,lli> p = q.front();
		q.pop();

		lli dx[2]={0,1};
		lli dy[2]={1,0};

		bool move = false;
		if(p.first == (h-1) && p.second == (w-1))move = true;
		REP(i,0,2){
			lli nextX = p.second+dx[i];
			lli nextY = p.first +dy[i];
			if(data[nextY][nextX]==0)continue;
			if(flag[nextY][nextX]==1){
				cout<<"Impossible"<<endl;
				return 0;
			}
			flag[nextY][nextX]=1;
			q.push(mp(nextY,nextX));
			move = true;
		}
		if(!move){
							cout<<"Impossible"<<endl;
				return 0;
		}
	}
	REP(i,0,h)REP(j,0,w){
		if(data[i][j]==1 && flag[i][j]==0){
			cout<<"Impossible"<<endl;
			return 0;
		}
	}
	cout<<"Possible"<<endl;



	return 0;
}