#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long> 
#define str string 
#define ch char
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

ll dp[3001][3001];
ll sums[3001][3001];
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    int n; cin>>n;
    ll ar[n];
    
    for(int i=0; i<n; i++){
        cin>>ar[i];
    }
    if(n==1) {cout<<ar[0]; return 0;}
    sums[0][0] = ar[0];
    for(int i=1; i<n; i++){
        sums[0][i] = sums[0][i-1] + ar[i];
    }
    for(int s=0; s<n; s++){
        for(int i=0; i<n-s; i++){
            if(s==0) sums[i][i] = ar[i];
            else sums[i][i+s] = sums[0][i+s] - sums[0][i-1];
        }
    }
    for (int s=0; s<n; s++){
        for(int i=0; i<n-s; i++){
            int start = i;
            int end = i+s;
            if(s==0){
                dp[start][end] = ar[i];
            }
            else{
                dp[start][end] = max(sums[start+1][end]-dp[start+1][end] + ar[start], 
                                    sums[start][end-1]-dp[start][end-1] + ar[end]);
            }
        }
    }
    cout<<dp[0][n-1]-min(dp[1][n-1], dp[0][n-2]);
}

