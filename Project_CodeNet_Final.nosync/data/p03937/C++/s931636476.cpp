#include <bits/stdc++.h>
 
using namespace std;
 
#define lli long long int
#define REP(i,s,n) for(int i=s;i<n;i++)
#define MOD 1000000007
#define NUM 2520
#define DEBUG 0
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())
#define PI (3.141592653589794)
#define INF (1LL<<50)

signed main(){

	lli h,w;
	cin>>h>>w;

	lli data[10][10]={0};
	REP(i,0,h)REP(j,0,w){
		char tmp;
		cin>>tmp;
		data[i][j]=(tmp=='#');
	}

	lli sx=0,sy=0;

	if(data[sy][sx]==0){
		cout<<"Impossible"<<endl;
		return 0;
	}

	while(1){
		data[sy][sx]=0;
		bool move=true;
		if(data[sy][sx+1]==1)sx++;
		else{
			if(data[sy+1][sx]==1)sy++;
			else{
				move=false;
			}
		}
		if(!move)break;
	}

	if( (sy != (h-1)) && (sx != (w-1)) ){
		cout<<"Impossible"<<endl;
		return 0;
	}

	for(lli i=0;i<h;i++)for(lli j=0;j<w;j++){
		if(data[i][j]){
			cout<<"Impossible"<<endl;
			return 0;
		}
	}
	cout<<"Possible"<<endl;
	return 0;
}