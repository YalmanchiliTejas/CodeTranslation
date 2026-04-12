#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class book{
public:
	ll t,a,b,flag;
};
bool compare(pair<ll,ll> p1,pair<ll,ll> p2){
  if(p1.second==p2.second) return p1.first>p2.first;
	return p1.second>p2.second;
}
bool comp(char a, char b)
{
    return (a < b);
}
int mex(int *A,int n){
	int C[n];
	for(int i=0;i<n;i++) C[i]=A[i];
	sort(C,C+n);
	for(int i=0;i<=n;i++){
		if(!binary_search(C,C+n,i)) return i;
	}
}
bool check(int *A,int n){
	for(int i=0;i<n-1;i++){
		if(A[i]>A[i+1]) return false;
	}
	return true;
}
bool subsetSum(vector<ll> arr, int n, int s){
	int dp[2][s+1];

	for(int i=0;i<=s;i++){
		dp[0][i] = false;
	}
    dp[0][0] = true;

    int flag = 1;

	for(int i=1;i<=n;i++){
		for(int j =1;j<=s;j++){
			dp[flag][j] = dp[flag^1][j];
			if(j-arr[i-1]>=0){
				dp[flag][j] = dp[flag][j] || dp[flag^1][j-arr[i-1]];
			}
		}
        flag^=1;
	}

 	return dp[flag^1][s];
}
int main() {
	// your code goes here


	int T=1;
	//cin>>T;

	while(T--){
	    // ll n;
			 //cin>>n;
			 ll a;
			 cin>>a;
			 if(a<30) cout<<"No"<<endl;
			 else cout<<"Yes"<<endl;

}
	return 0;
}
