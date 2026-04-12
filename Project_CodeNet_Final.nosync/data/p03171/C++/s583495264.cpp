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
int n,arr[3001];
pair<int,int> dp[3001][3001][2];
pi rec(int l,int r,int cur){
	if(l==r){
		if(cur==0){
			return make_pair(arr[l],0);
		}
		else
			return make_pair(0,arr[l]);
	}
	if(l>r)
		return make_pair(0,0);
	if(dp[l][r][cur].F != -1)
		return dp[l][r][cur];
	if(cur == 0){
		pi a =  rec(l+1,r,1);
		pi b =  rec(l,r-1,1);
		a.F += arr[l];
		b.F += arr[r];
		if(a.F - a.S > b.F - b.S){
			dp[l][r][0] = a; 
		}
		else
			dp[l][r][0] = b;
		return dp[l][r][0];
	  }
	    pi a =  rec(l+1,r,0);
		pi b =  rec(l,r-1,0);
		a.S += arr[l];
		b.S += arr[r];
		if(a.F - a.S < b.F - b.S){
			dp[l][r][1] = a; 
		}
		else
			dp[l][r][1] = b;
	return dp[l][r][1];
}
int32_t main(){


	FASTIO;
	cin >> n;
	REP(i,0,n){
		cin >> arr[i];
	}
	REP(i,0,n){
		REP(j,0,n){
			REP(k,0,2){
				dp[i][j][k] = {-1,-1};
			}
		}
	}
	pi hehe = rec(0,n-1,0);
	cout << hehe.F - hehe.S << endl;
    return 0;

}