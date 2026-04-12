#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define int long long
const int MOD=1e9+7;
const int INF=1e15;

signed main(){
    string S;
    int K;cin>>S>>K;
    int c=S.size();
    vector<vector<int>>dpk(c+1,vector<int>(K+1,0));
  	vector<vector<int>>dpm(c+1,vector<int>(K+1,0));
  	dpk[1][1]=S[0]-'0'-1;
  	dpk[1][0]=1;
  	dpm[1][1]=1;
    for(int i=1;i<=c;i++){
        dpk[i][0]+=dpk[i-1][0];
      	for(int j=1;j<=K;j++){
            dpk[i][j]+=dpk[i-1][j-1]*9+dpk[i-1][j];
            if(S[i-1]!='0'){
                int d=S[i-1]-'0';
              	dpk[i][j]+=dpm[i-1][j]+dpm[i-1][j-1]*(d-1);
                dpm[i][j]+=dpm[i-1][j-1];
            }
            else{
                dpm[i][j]=dpm[i-1][j];
            }
        }
    }
  	cout<<dpk[c][K]+dpm[c][K]<<endl;
}