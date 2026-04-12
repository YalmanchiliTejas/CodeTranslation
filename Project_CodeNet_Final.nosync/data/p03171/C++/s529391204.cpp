#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define ll long long
#define ld long double
#define pb push_back
#define INF 1e9

ll solveA(int i,int j,vector <int>& A,ll sum, vector <vector <ll> >& dp){
    if(dp[i][j]>=0) return dp[i][j];
    if(i==j){ dp[i][j]=A[i]; return A[i];}
    dp[i][j] = max(sum-solveA(i+1,j,A,sum-A[i],dp),sum-solveA(i,j-1,A,sum-A[j],dp));
    return dp[i][j];
}

int main(){
    int n;
    cin>>n;
    vector <int> A (n);
    ll sum = 0;
    for(int i=0;i<n;i++){ cin>>A[i]; sum+=A[i]; } 
    vector <vector <ll> > dp (n+1,vector <ll> (n+1,-1));
    cout<<(ll)2*solveA(0,n-1,A,sum,dp)-(ll)sum<<"\n";
	return 0;
}
