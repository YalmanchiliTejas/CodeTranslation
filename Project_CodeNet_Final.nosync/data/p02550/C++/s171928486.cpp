#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000



int main(){

	long long N;
	cin>>N;
	int X,M;
	cin>>X>>M;
	vector<vector<pair<int,long long>>> nxt(40,vector<pair<int,long long>>(M));
	
	rep(i,40){
		rep(j,M){
			if(i==0){
				nxt[i][j] = make_pair(((long long)j*j)%M,((long long)j*j)%M);
			}
			else{
				nxt[i][j] = make_pair(nxt[i-1][nxt[i-1][j].first].first, nxt[i-1][j].second + nxt[i-1][nxt[i-1][j].first].second);
			}
			
			
		}
	}
	/*
	rep(i,5){
		rep(j,10){
			cout<<i<<','<<j<<','<<nxt[i][j].first<<','<<nxt[i][j].second<<endl;
		}
	}
	*/

	int now = X%M;
	long long ans = now;
	N--;
	
	rep(i,40){
		if((N>>i)&1){
			ans += nxt[i][now].second;
			now = nxt[i][now].first;
		}
	}
	
	cout<<ans<<endl;

	return 0;
}

