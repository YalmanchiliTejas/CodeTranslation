/*
Problem Number: ABC177C
Problem Name: Sum of product of pairs
Notes: 
*/

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define MOD 1000000007

using namespace std;

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    
    int n;
    cin >> n;
    ll a, sum = 0, sol = 0;
    for(int i = 0; i < n; i++)
        cin >> a, sol = (sol + a * sum) % MOD, sum = (sum + a) % MOD;
    cout << sol << endl;
    
    return 0;
}