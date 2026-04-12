#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <cmath>
#include <functional>
#include <set>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <utility>
 
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORE(i,a,b) for(int i = a;i<=b;i++)
#define ll long long int
#define ii pair<int,int>
#define mp make_pair
#define pb push_back
#define iii pair<ii,int >
#define ff first
#define ss second
#define vi vector<int>
#define vc vector<char>
 
using namespace std;


int main(){
	int n;
	cin >> n;
	ll arr[n];
	FOR(i,n)cin >> arr[i];
	ll dp[n][n];
	FOR(i,n)FOR(j,n)dp[i][j] = 0;
	ll pref[n];
	pref[0] = arr[0];
	FORE(i,1,n-1)pref[i] = pref[i-1] + arr[i];
	FOR(k,n){
		FOR(i,n-k){
			if(k == 0){
				dp[i][i+k] = arr[i];
			}else if(k == 1){
				dp[i][i+k] = max(arr[i],arr[i+1]);
			}else{
				dp[i][i+k] = max(arr[i] + (pref[i+k] - pref[i]) - dp[i+1][i+k] ,
				 arr[i+k] + pref[i+k-1] - ((i>0)?pref[i-1]:0) - dp[i][i+k-1]);
			}
		}
	}
	ll x = dp[0][n-1];
	ll y = pref[n-1] -x;
	cout << x - y << endl;
	return 0;
}
