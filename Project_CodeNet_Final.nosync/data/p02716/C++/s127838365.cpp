#include <bits/stdc++.h>
#define ll long long
#define intm INT_MAX
#define llm LLONG_MAX

using namespace std;
int MOD = 998244353;

ll ar[200009];
int N;
ll dp[200009];
ll odd[200009];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> N;
	for(int i=1; i <= N; i++) cin >> ar[i];
	odd[1] = ar[1];
	for(int i=2; i <=N; i++){
        if(i%2!=0) odd[i] = odd[i-2]+ ar[i];
	}
	dp[0] = dp[1] = 0;
	for(int i=2; i <= N; i++){
        dp[i] = dp[i-2] + ar[i];
        if( i % 2 == 0 ) dp[i] =  max( dp[i], odd[i-1] );
        else{
            dp[i] = max(dp[i], dp[i-1] );
        }
	}
	cout << dp[N];

}
