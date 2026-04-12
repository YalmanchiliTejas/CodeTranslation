#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
#include<math.h>
#include<map>
#include<unordered_map> 
#include<vector>
#include<queue>
#include<set>
#include<deque> 
#include<bitset>
#include<string>
#define N 40
#define K 300005
#define MOD 1e9+7
#define int long long 
#define fastio  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int mod = 1e9 + 7;
int lim = 1e4 +1;

//denotes the number of numbers for pos i...end with rem of digit sum = j
//3rd index is for 0 if on border and 1 if not on border
int dp[10005][105][2];

string no;
int d;

int max(int a, int b){
	if(a > b)
		return a;
	return b;
}

int solve(int pos, int rem, int bor){
    //cout<<pos<<" "<<rem<<" "<<bor<<" "<<no[pos]<<endl;
    if(pos == lim){
        if(rem == 0)
            return 1;
        else
            return 0;
    }
    if(dp[pos][rem][bor] != -1)
        return dp[pos][rem][bor];
	int ans = 0;
	if(bor == 1){
		int last = no[pos] - '0';
		for(int i=0;i<=last;i++){
            int j = i %d;
			int rem_req = (rem + d - j)%d;
			if(i == last)
				ans += solve(pos + 1, rem_req, 1);
			else
				ans += solve(pos + 1, rem_req, 0);
			if(ans >= mod)
				ans %= mod;
		}
	}
	else{
		for(int i=0;i<10;i++){
            int j = i%d;
			int rem_req = (rem + d - j)%d;
			ans += solve(pos + 1, rem_req, 0);
			if(ans >= mod)
				ans %= mod;
		}
	}
    //cout<<pos<<" "<<rem<<" "<<ans<<endl;
	dp[pos][rem][bor] = ans;
	return dp[pos][rem][bor];
}

int32_t main(){
	cin>>no;
	cin>>d;
	
	int pad = lim - no.length();
	for(int i=0;i<pad;i++)
		no = '0' + no;
    //cout<<no<<endl;
	for(int i=0;i<lim;i++){
		for(int j=0;j<=100;j++){
			dp[i][j][0] = -1;
            dp[i][j][1] = -1;
		}
	}
    //cout<<"DDD"<<endl;
    //exit(0);
	int a1 = solve(0,0,1);
    //int a2 = solve(1,0, 1);
    //cout<<a1 -1<<endl;
	cout<<(a1 + mod - 1)%mod<<endl;
    
    

	
	
	
}

