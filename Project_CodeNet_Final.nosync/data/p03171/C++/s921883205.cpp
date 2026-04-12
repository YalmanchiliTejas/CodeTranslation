#include <bits/stdc++.h>

using namespace std;

long long int n,i;
long long int tablica[3003];
long long int visited[3003][3003];
long long int dp[3003][3003];

long long int licz(long long int lewy, long long int prawy)
{
    if(visited[lewy][prawy])
    {
        return dp[lewy][prawy];
    }
    visited[lewy][prawy]=true;
    if(lewy==prawy)
    {
        dp[lewy][prawy]=tablica[prawy];
        return dp[lewy][prawy];
    }
    dp[lewy][prawy] = max(tablica[lewy]-licz(lewy+1, prawy), tablica[prawy]-licz(lewy, prawy-1));
    return dp[lewy][prawy];
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(i=0;i<n;i++){
        cin >> tablica[i];
    }
    cout << licz(0,n-1);
    return 0;
}
