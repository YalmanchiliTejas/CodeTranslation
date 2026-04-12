#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


int main() {
    string n;
    int k;
    cin >> n >> k;
    int m=n.size();
    vector<int> d(m);
    for (int i=0;i<m;i++) d[i]=n[i]-'0';
    vector<vector<int>> p;
    vector<vector<int>> dp0(m+1,vector<int>(k+1)),dp1(m+1,vector<int>(k+1));
    for (int i=0;i<m+1;i++) {
        for (int j=0;j<k+1;j++) {
            dp0[i][j]=0;
            dp1[i][j]=0;
        }
    }
    dp0[1][0]=1;
    dp0[1][1]=d[0]-1;
    dp1[1][1]=1;
    for (int i=2;i<=m;i++) {
        dp0[i][0]=1;
        for (int j=1;j<=min(i,k);j++) {
            if (d[i-1]>0) {
                dp0[i][j]=dp0[i-1][j]+9*dp0[i-1][j-1]+dp1[i-1][j]+(d[i-1]-1)*dp1[i-1][j-1];
                dp1[i][j]=dp1[i-1][j-1];
            } else {
                dp0[i][j]=dp0[i-1][j]+9*dp0[i-1][j-1];
                dp1[i][j]=dp1[i-1][j];
            }
        }
    }
    cout << dp0[m][k]+dp1[m][k] << endl;
}