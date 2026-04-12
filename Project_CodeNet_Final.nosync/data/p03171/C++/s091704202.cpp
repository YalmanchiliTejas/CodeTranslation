#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define F first
#define S second
#define MAX 10000000
#define MOD 1000000007
#define off ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

typedef pair<int, int> PII;

signed main(){
    off;
    int N;
    cin>>N;
    int arr[N];
    int sum = 0;
    for(int i=0; i<N; i++){
        cin>>arr[i];
        sum += arr[i];
    }
    int dp[N][N];
    for(int L=0; L<N;L++){
        for(int i=0, j=L; j<N; ++i, ++j){
            int x = ((i + 2) <= j) ? dp[i + 2][j] : 0; 
            int y = ((i + 1) <= (j - 1)) ? dp[i + 1][j - 1] : 0; 
            int z = (i <= (j - 2)) ? dp[i][j - 2] : 0; 
  
            dp[i][j] = max(arr[i] + min(x, y), arr[j] + min(y, z)); 
        }
    }
    cout<<2*dp[0][N-1] - sum<<endl;
    return 0;
}