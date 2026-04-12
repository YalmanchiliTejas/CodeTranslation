#include <bits/stdc++.h>
using namespace std;

#define FAST {ios::sync_with_stdio(false); cin.tie(NULL);}
#define pb push_back
#define fi first
#define se second
#define ll long long int
#define f(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007

ll dp[3005][3005] = {0};

int main(){

    FAST
	
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0;i<n;i++)
    	cin>>arr[i];

    for(int i=n-1;i>=0;i--){
    	for(int j=i;j<n;j++){
    		if(i == j){
    			dp[i][j] = arr[i];
    		}
    		else{
    			dp[i][j] = max(arr[i] - dp[i+1][j], arr[j] - dp[i][j-1]);
    		}
    	}
    }
    cout<<dp[0][n-1]<<"\n";
    return 0;
}
