#include <bits/stdc++.h>
#define in freopen("input.txt", "r" ,stdin)
#define out freopen("output.txt", "w" , stdout)
#define ll long long
#define inf 200005
#define fr first
#define  sc second
#define pb push_back
#define p_b pop_back
#define p_f pop_front
#define mp make_pair
#define N 100100
#define mod 1000000007
#define pi 3.1415926535
using namespace std;
int n;
ll a[3035];
ll dp[3035][3035];
ll brute (ll l , ll r , ll t) {
    if (l == r){
            return 0;
    }
    if (dp[l][r] != -1) return dp[l][r];
    ll res = 0;
    if (t == 1) {
        res = max (brute (l+1,r,2) + a[l] , brute (l ,r-1,2) + a[r-1]);
    }
    else res = min (brute(l+1,r,1) - a[l] , brute (l,r-1,1) - a[r-1]);

    return dp[l][r]=res;
}
int main (){
//in;out;
ios_base::sync_with_stdio(0);
cin >> n;
for (int i = 1; i <= 3030; i++){
    cin >> a[i];
}
for (int i = 0; i <=3030; i++){
    for (int j = 0; j <= 3030; j++){
        dp[i][j] = -1;
    }
}
cout << brute (1, n+1 ,1);
}
