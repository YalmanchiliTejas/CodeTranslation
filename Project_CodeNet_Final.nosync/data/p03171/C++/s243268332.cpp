#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<functional>
#include<iomanip>
#include<iostream>
#include<list>
#include<map>
#include<queue>
#include<random>
#include<set>
#include<stack>
#include<string>
#include<utility>
#include<vector>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define FORR(i,a,b) for(int i=(a);i>=(b);--i)
#define REPR(i,n)   FORR(i,n,0)
#define int long long

using namespace std;
typedef pair<int, int> pii;

int n,a[3010]={0},dp[3010][3010]={0};

int cal(int i,int j){
    if(j<=i){
        return dp[i][j]=0;
    }
    else{
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        else{
            return dp[i][j]=max(a[i]-cal(i+1,j),a[j-1]-cal(i,j-1));
        }
    }
}

signed main() {
	cin>>n;
    rep(i,n){
        cin>>a[i];
    }

    rep(i,n+1){
        rep(j,n+1){
            dp[i][j]=-1;
        }
    }
	
    cout<<cal(0,n)<<endl;
	
	return 0;
}
