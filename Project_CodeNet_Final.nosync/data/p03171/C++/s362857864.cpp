#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <typeinfo>
using namespace std;

#define ll long long 

 
int main()
{
    int N;
    cin >> N;
    ll arr[N];
    ll dp[N+1][N+1]; 
    fill(*dp, *dp + ((N+1)*(N+1)), 0);
    for (int i =0; i<N; ++i){
        cin >> arr[i];
    }
    ll ans;
    for (int i=N-1; i>=0; --i){
        for (int j=i; j<=N; ++j){
            if (j < 0)
                continue;
            dp[i][j] = max(arr[i] - dp[i+1][j], arr[j] - dp[i][j-1]);
        }
    }
    cout <<dp[0][N-1];
    return 0;
}