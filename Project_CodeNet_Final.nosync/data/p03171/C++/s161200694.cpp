// Author : Rifayat Samee (Sanzee)
// Problem :
// Algorithm:

/*

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll memo[3001][3001];
ll dp(int i,int j,const vector<ll>&A){
    if(i>j)return 0;
    if(i == j) return A[i];
    if(memo[i][j] != -1)
        return memo[i][j];
    ll res = 0;
    ll r1 = min(dp(i+2,j,A)+A[i],dp(i+1,j-1,A)+A[i]);
    ll r2 = min(dp(i+1,j-1,A)+A[j],dp(i,j-2,A)+A[j]);
    res = max(r1,r2);
    memo[i][j] = res;
    return res;
}

int main(){

	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
    int n;
    scanf("%d",&n);
    vector<ll>A(n+1);
    ll sum = 0;
    for(int i=0;i<n;i++){
        scanf("%lld",&A[i]);
        sum += A[i];
    }
    memset(memo,-1,sizeof(memo));
    ll res = dp(0,n-1,A);
    printf("%lld\n",2*res - sum);
	return 0;
}
