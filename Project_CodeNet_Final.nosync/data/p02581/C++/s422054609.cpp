#include <bits/stdc++.h>
using namespace std;

#define MAXN 2001
int n, a[3*MAXN], mxk[MAXN], mx, tri;

vector<tuple<int,int,int>> ops;
void maxi(int i, int j, int v) {
    ops.emplace_back(i,j,v);
}

void maxip(int i, int j, int v) {
    if (~v) {
        ops.emplace_back(i,j,v+1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1)); 
    fill(mxk, mxk+n+1, -1);
    for (int i = 0; i < 3*n; ++i)cin>>a[i];
    dp[a[0]][a[1]] = mxk[a[0]] = mxk[a[1]] = 0;
    for (int i = 0; i < n-1; ++i) {
        int p=a[i*3+2],q=a[i*3+3],r=a[i*3+4];
        if (p==q && q==r) {
            tri++;
        } else {
            if(p == q || q == r || p == r){
                int d, u;
                if(p == q)d = p, u = r;
                if(q == r)d = q, u = p;
                if(p == r)d = p, u = q;
                for (int k = 1; k <= n; ++k) {
                    maxip(k, u, dp[k][d]);
                    maxip(k, u, dp[d][k]);
                }
            }
            maxip(q, r, dp[p][p]);
            maxip(p, r, dp[q][q]);
            maxip(p, q, dp[r][r]);
            maxi(q, r, mx);
            maxi(p, r, mx);
            maxi(p, q, mx);
            for (int k = 1; k <= n; ++k) {
                maxi(k, p, mxk[k]);
                maxi(k, q, mxk[k]);
                maxi(k, r, mxk[k]);
            }
            for (auto &o: ops) {
                int i=get<0>(o), j=get<1>(o), v=get<2>(o);
                dp[i][j] = max(dp[i][j], v);
                mxk[i] = max(mxk[i], v);
                mxk[j] = max(mxk[j], v);
                mx = max(mx, v);
            }   
            ops.clear();
        }
    }
    cout<<max(mx, dp[a[n*3-1]][a[n*3-1]] + 1) + tri;
}