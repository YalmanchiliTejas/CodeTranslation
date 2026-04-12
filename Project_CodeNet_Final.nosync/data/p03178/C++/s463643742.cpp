#include <bits/stdc++.h>
 
using namespace std;
 
#define mp make_pair
#define endl '\n'
using ll=long long;
 
const int INF=1e9+5;
const ll lim=(ll)3e16;
const int N=1e5+5;
const int mod=1e9+7;
const ll oo=1e18+5;
 
// dp[i] is the number of numbers that sum diggit  
// 10000 number of digits

void add_self(int& a,int b){
	a+=b;
	if(a>=mod) a-=mod;
}

void sub_self(int& a,int b){
	a-=b;
	if(a<0) a+=mod;
}

string k;
int d;

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
	cin>>k>>d;
	// cout<<k<<" "<<d<<endl;
	// return 0;
	int len=k.size();
	vector<vector<int>> dp(d,vector<int>(2));
	// dp[sum][pre_small] is the number of ways choose digit that sum of digits is sum and check is true if pre digit is small than k[pre_id]
	// note : avoid cur_num > k
	dp[0][0]=1;
	for(int cur_pos=0;cur_pos<len;++cur_pos){
		vector<vector<int>> cur_dp(d,vector<int>(2));
		for(int sum=0;sum<d;++sum){
			for(int is_smaller=0;is_smaller<2;++is_smaller){
				for(int digit=0;digit<10;++digit){
					if(digit>k[cur_pos]-'0'&&!is_smaller){
						break;
					}
					add_self(cur_dp[(sum+digit)%d][is_smaller||(digit<k[cur_pos]-'0')],dp[sum][is_smaller]);
				}
			}
		}
		dp=cur_dp;
	}
	add_self(dp[0][0],dp[0][1]);
	sub_self(dp[0][0],1);
	cout<<dp[0][0]<<endl;
	return 0;
}

