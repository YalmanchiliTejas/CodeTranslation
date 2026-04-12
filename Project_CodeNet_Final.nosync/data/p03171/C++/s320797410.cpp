// #include<bits/stdc++.h>
// using namespace std;
 
// const int N = 100000, MAXI = 3, D = 1000;
 
// int main() {
//     freopen("output.txt", "r", stdin);
//     freopen("input.txt", "w", stdout);
//     srand(time(nullptr));
//     int tc = 10000, flag = 1;
//     cout << tc << "\n";
//     int n = 1;
//     while (tc--)
//     {
//     	n = rand()%N + 1;

//     	cout << n << "\n~\n";

//     }
 
//     return 0;
// }
 
 
 
 
 
 
 
 
//---------------------------------------------//
 
 
 
/*
#define int long long 
#define mod (int)(1e9+9)
#define endl '\n'
#define MAXI (int)(3e17+10)
#define N 200005
 */ 
 
 
 
 

//  /* while(!cin.eof()) */
 
#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define mod (int)(1e9+7)
#define MAXI (int)(3e17+10)
#define N 3005

int dp[N][N][2], n, a[N];

int MEM(int i, int j, int last)
{
	if(i==j){
		if(last==0)
			return 0;

		return a[i];
	}

	int ans = dp[i][j][last];
	
	if(ans!=-1)
		return ans;

	if(last==1)
	{
		ans = -1*MAXI;
		ans = max(ans, a[i] + MEM(i+1, j, 0));
		ans = max(ans, a[j] + MEM(i, j-1, 0));
		dp[i][j][last] = ans;
	}
	else
	{
		ans = MAXI;
		ans = min(ans, MEM(i+1, j, 1));
		ans = min(ans, MEM(i, j-1, 1));
		dp[i][j][last] = ans;
	}

	return dp[i][j][last];
}

// Driver code to test above functions
int32_t main()
{
    
     
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int sum = 0;
    cin >> n;
    for(int i=0;i<n;i++){
    	cin >> a[i];
    	sum += a[i];
    }

    memset(dp, -1, sizeof dp);

    cout << 2*MEM(0, n-1, 1) - sum; 
    

    return 0;
 
} 