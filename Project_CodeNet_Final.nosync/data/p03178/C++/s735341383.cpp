#include <bits/stdc++.h>
#define F first
#define S second
#define all(a) a.begin(),a.end()
#define setDP(arr) memset(arr,-1,sizeof arr)
#define Clear(arr) memset(arr,0,sizeof arr)
#define li(x) x.size()-1
#define oo 1000000000
#define inf 1000000000000000000
#define M 1000000007
#define M2 1000000009
#define pii pair<ll,ll>
using namespace std;
typedef long long ll;
const int N = 2e5+100;
const int SQRTN = 320;
const int LOGN = 20;
const double PI = acos(-1);
 
int dp[N][111][2];
char s[N];
int n,d;
int calc(int idx , int sum,bool b){
	
	if(idx==n){
		return !sum;
	}
 
	int&ret = dp[idx][sum][b];
	if(ret!=-1)
		return ret;
	ret = 0;
	for(int i = 0 ; i<=(b?9:(s[idx]-'0')) ; i++){
		
		ret +=calc(idx+1,(sum+i)%d,b||(i<s[idx]-'0'));
		ret%=M;
	}
 
	return ret;
}
 
int main() {
	scanf("%s",s);
	n = strlen(s);
	cin >> d;
	setDP(dp);
	cout << (calc(0,0,0)+M-1)%M<< endl;
 
 
    return 0;
}