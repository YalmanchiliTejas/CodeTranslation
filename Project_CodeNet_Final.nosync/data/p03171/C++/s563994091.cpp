#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int  MOD=1000000007;
const int  INF= int(1e9);
const int  MAX= 3007;

ll dp[MAX][MAX],a[MAX];

/*
 * dp[p][q] = best score of X-Y
 */


ll solve(int p , int q ) {
    if(dp[p][q] != -1) {
        return dp[p][q];
    }

    if( p > q ) {
        return 0;
    }

    if(p == q) {
        return dp[p][q] = a[p];
    }    


    return dp[p][q]=max(solve(p,p) - solve(p+1,q) , solve(q,q) - solve(p,q-1));
}


int main() {
    ios_base::sync_with_stdio(false);
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            dp[i][j] = -1;
        }
    }
    int n;
    cin >> n;
    for(int i = 1; i <= n ; i++) {
        cin >> a[i];
    }

    cout<<solve(1,n)<<endl;

    return 0;
}

