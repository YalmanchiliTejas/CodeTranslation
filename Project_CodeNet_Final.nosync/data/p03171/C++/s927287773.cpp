#include <bits/stdc++.h>
#define ll long long
#define PI 3.141592653589
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define EPS 1e-9
using namespace std;
int n;
ll memo[3005][3005];
int arr[3005];
ll solve(int i, int j){
    if(i == j)
        return arr[i];
    ll &ans = memo[i][j];
    if(ans != -1)
        return ans;
    return ans = max(arr[i]-solve(i+1, j), arr[j]-solve(i, j-1));
}
int main(){
    IO;
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
    memset(memo, -1, sizeof memo);
    cout << solve(0, n-1);

    return 0;
}
