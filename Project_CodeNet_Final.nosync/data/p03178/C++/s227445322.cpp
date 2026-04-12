#include <iostream>
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pii std::pair<int,int>
#define pli std::pair<ll,int>
#define pil std::pair<int,ll>
#define psi std::pair<string,int>
#define pll std::pair<ll,ll>
#define pci std::pair<char,int>
#define sll(x) scanf("%lld",&x)
#define prll(x) printf("%lld ",x)
#define pri(x) printf("%d ",x)
#define si(x) scanf("%d",&x)
#define pb push_back
#define vll std::vector<ll>
#define vpi std::vector<std::pair<int,int>>
#define vi std::vector<int>
#define vvi std::vector<std::vector<int>>
#define vvpil std::vector<std::vector<std::pair<int,ll>>>
#define vlpii std::vector<std::list<pii>>
#define vlpil std::vector<std::list<pil>>
#define li std::list<int>
#define lpil std::list<pil>
#define Endl printf("\n")
#define vli vector<list<int>>
#define vvll vector<vector<ll>>
#define mp make_pair
#define ma 100000000
#define imie(...) "[" << #__VA_ARGS__": " << (__VA_ARGS__) << "] "
const ll  INF=10000000000000;
const ll mod = 1e9 + 7;
using namespace std;
void add(int& a , int b){
	a += b;
	if(a >= mod) a -= mod;
}
ll mul(ll a , ll b){
	return (a * b) % mod;
} 
int main()
{
	
	string k ; cin >> k;
	int d ; cin >> d;
	int n; n = k.size() ;
	vector<vector<int> > dp(d , vector<int>(2)) ;
	dp[0][0] = 1 ;
	for(int i = 0 ; i< n ; i++){
		vector<vector<int> > new_dp(d , vector<int> (2)) ;
		for(int sum = 0 ; sum < d; sum++){
			for(int sum_already = 0 ; sum_already < 2 ; ++sum_already){
				for(int digit = 0 ; digit < 10 ; ++digit){
					if(digit > k[i] - '0' && !sum_already) break ;
					add(new_dp[(sum + digit) % d][sum_already || digit < k[i] - '0'] , dp[sum][sum_already]) ;
				}
			}
		}
		dp = new_dp ;
	}
	add(dp[0][0] , dp[0][1]) ;
	dp[0][0] -= 1;
	if(dp[0][0] < 0 ) dp[0][0] += mod;
	cout << dp[0][0]  << "\n" ;
	
	return 0;
}
	

