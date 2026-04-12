#include <bits/stdc++.h>
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)
	
using namespace std;
typedef pair<int,int> P;
const int MAX_N=2e5;
int N;
P X[MAX_N];
int ans[MAX_N];
int main(){
	cin>>N;
	REP(i,N){
		int x;
		cin>>x;
		X[i]=P(x,i);
	}
	sort(X,X+N);
	REP(i,N){
		if (i<N/2){
			ans[X[i].second]=X[N/2].first;
		}else{
			ans[X[i].second]=X[N/2-1].first;
		}
	}
	REP(i,N){
		cout<<ans[i]<<endl;
	}
	
	return 0;
}