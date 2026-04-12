#include <bits/stdc++.h>

using namespace std ;

const int MAX = 110 ;

int arr[MAX] ;
int n , k ;

long long dp[MAX][MAX][2];

vector<int>v ;

long long calc(int idx , int dig , bool Less)
{
	if(dig > k)
		return 0 ;
	if(idx == v.size())
	{
		if(dig == k)
			return 1ll ;
		else
			return 0ll ;
	}
	long long &ret = dp[idx][dig][Less] ;
	if(ret != -1)
		return ret ;
	int LMT ;
	if(Less == 0)
		LMT = v[idx] ;
	else
		LMT = 9 ;
	ret = 0 ;
	for(int i = 0 ; i <= LMT ; ++i)
	{
		bool nLess = Less ;
		int ndig  = dig ;
		if(i < LMT)
			nLess = 1 ;
		if(i != 0)
			ndig++ ;
		ret += calc(idx+1 , ndig , nLess) ;
	}
	return ret ;
}

long long solve(string s)
{
	memset(dp , -1 , sizeof(dp)) ;
	for(int i = 0 ; i < s.size() ; ++i)
		v.push_back((s[i] - '0')) ;
	return calc(0 , 0 , 0) ;
}

int main()
{
	ios_base::sync_with_stdio(0) ;
	cin.tie(0) ;
	string n ;
	cin>>n ;
	cin>>k ;
	return cout<<solve(n)<<"\n" , 0 ;
}		