#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <vector>
#include <bitset>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <deque>
#include <string>
#include <list>
#include <iterator>
#include <algorithm>
#include <unordered_map>
#define int                long long
#define pb                 push_back
#define pi                 pair<int,int>
#define vi                 vector<int>
#define all(v)             v.begin(),v.end()
#define MOD                1000000007
#define F                  first
#define S                  second
#define FOR(i,r)           for(int i=0;i<r;i++)
#define REP(i,l,r)         for(int i=l;i<r;i++)
#define RER(i,l,r)         for(int i=l;i>=r;i--)
#define print(v)           for(auto i : v)cout << i << ' ';
#define FASTIO             ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mem(arr,k)         memset(arr,k,sizeof(arr));
#define pii                acos(-1.0)
#define PI                 3.1415926535897932385
#define Sin(a)             sin((pi*a)/180)
#define test()             int x;cin >> x;while(x--)
using namespace std;
int dp[10001][101][2],d;
string str;
int rec(int i,int s,int e){
	if(s < 0)
		return 0;
	if(i == str.size()){
		if(s==0)
		return 1;
		return 0;
	}
	if(dp[i][s][e]!=-1)
		return dp[i][s][e];
	int ways = 0;
	if(e){
		for(int j=0;j<=str[i]-'0';j++){
			if(j != str[i]-'0'){
				ways += rec(i+1,(s+j)%d,0);
			}
			else
				ways += rec(i+1,(s+j)%d,1);
			ways %= MOD;
		}
	}
	else{
		for(int j=0;j<=9;j++){
			ways += rec(i+1,(s+j)%d,0);
		}
		ways %= MOD;
	}
	dp[i][s][e] = ways;
	return ways;
}
int32_t main(){

	
	FASTIO;
	mem(dp,-1);
	//string str;
	cin >> str >> d;
	cout << (rec(0,0,1)-1+MOD)%MOD << endl;
    return 0;

}