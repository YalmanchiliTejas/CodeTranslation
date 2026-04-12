#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

vector<vector<long long int> > dp(101,vector<long long int>(4,-1));

long long int digitSum(const string &a,int idx,int k,bool tight,const int &n){
	if(idx==n)
		return k==0?1:0;
	if(tight){
		if(!k)
			return digitSum(a,idx+1,k,a[idx]-48==0?1:0,n);
		long long int ans = digitSum(a,idx+1,k,a[idx]-48==0?1:0,n);
		for(int i=1;i<=a[idx]-48;i++)
			ans += digitSum(a,idx+1,k-1,i==(a[idx]-48),n);
		return ans;
	} else {
		if(dp[idx][k]!=-1)
			return dp[idx][k];
		if(!k)
			return dp[idx][k] = 1;
		dp[idx][k] = digitSum(a,idx+1,k,0,n);
		for(int i=1;i<10;i++)
			dp[idx][k] += digitSum(a,idx+1,k-1,0,n);
		return dp[idx][k];
	}
}

int main()
{
    string a;
    int k,n;
    cin >> a >> k;
    n = a.size();
    cout << digitSum(a,0,k,1,n);
    return 0;
}