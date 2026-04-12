#include <bits/stdc++.h>

using namespace std;
#define mp make_pair
#define all(x) (x).begin(), (x).end()
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvl;
typedef pair<int,int> pii;
typedef long long ll;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vl a(n);
    int i;
    vl se(n,0), so(n,0);
    for(i=0;i<n;i++){
        cin >> a[i];
        if(i > 0){
            se[i] += se[i-1];
            so[i] += so[i-1];
        }
        if(i%2==0) se[i] += a[i];
        else so[i] += a[i];
    }
    
    vl dp(n);
    dp[0] = 0;
    dp[1] = max(a[0],a[1]);
    for(i=2;i<n;i++){
        if(i%2==1){
            dp[i] = max(a[i] + dp[i-2], se[i-1]);
        }else{
            dp[i] = max(a[i] + dp[i-2], dp[i-1]);
        }
    }

    cout << dp[n-1] << endl;

    return 0;
}