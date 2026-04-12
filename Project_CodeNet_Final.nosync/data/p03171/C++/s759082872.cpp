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
#include<bits/stdc++.h>
#include<deque> 
#include<bitset>
#include<string>
#define N 1e6
#define K 300005
#define MOD 1e9+7
#define int long long 
#define fastio  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
 
int max(int a, int b){
    if(a>b)
        return a;
    return b;
}
int min(int a, int b){
    if(a<b)
        return a;
    return b;
}
 
int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
} 



int32_t main(){
	int n;
	cin>>n;
	int a[n + 1];
	int sum = 0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum += a[i];
	}
	//1st index is the length and the second one is the start point
	int dp[n + 1][n + 1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			dp[i][j] = 0;
		}
	}
	for(int len = 1; len<=n;len++){
		for(int left = 1; left <= n; left++){
			int right = left + len - 1;
			if(right > n)
				continue;
			if(len == 1){
				dp[len][left] = a[left];
                continue;
                //cout<<left<<" "<<dp[len][left]<<endl;
			}
			//i choose left
			int op1 = a[left] + min(dp[len-2][left + 2], dp[len-2][left + 1]);
			//i choose right
			int op2 = a[right] + min(dp[len-2][left], dp[len-2][left+1]);
			dp[len][left] = max(op1, op2);
            //cout<<len<<" "<<left<<" "<<right<<" "<<dp[len][left]<<endl;
			
		}	
	}
	int x = dp[n][1];
    //cout<<x<<endl;
	int y = sum -x;
	cout<<x - y;


	
}






