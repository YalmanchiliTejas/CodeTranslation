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



int32_t main(){
	cin>>no;
	cin>>d;
	
	int pad = lim - no.length();
	for(int i=0;i<pad;i++)
		no = '0' + no;
	//it will be on the border as the first digit is always one
	dp[0][0][1] = 1;
	for(int pos = 1; pos <lim; pos++){
		for(int sum = 0; sum < d; sum ++){
			for(int bor = 0; bor<2; bor++){
				if(bor == 0){
					for(int dig = 0; dig <10; dig++){
						int v = dig %d;
						int req = (sum + d - v)%d;
						dp[pos][sum][bor] += dp[pos - 1][req][0];
						if(dp[pos][sum][bor] >= mod)
							dp[pos][sum][bor] %= mod;
					}
					int last_poss = no[pos] - '0';
					for(int i=0;i<last_poss;i++){
						int v = i%d;
						int req = (sum + d - v)%d;
						dp[pos][sum][bor] += dp[pos - 1][req][1];
						if(dp[pos][sum][bor] >= mod)
							dp[pos][sum][bor] %= mod;
					}	
				}
				else{
					int last_poss = (no[pos] - '0')%d;
					int req = (sum + d - last_poss)%d;
					dp[pos][sum][bor] += dp[pos-1][req][1];
					if(dp[pos][sum][bor] >= mod)
						dp[pos][sum][bor] %= mod;
				}
			}
		}
	}
    
	cout<<(dp[lim-1][0][0] + dp[lim-1][0][1] + mod - 1)%mod<<endl;
    
    

	
	
	
}


