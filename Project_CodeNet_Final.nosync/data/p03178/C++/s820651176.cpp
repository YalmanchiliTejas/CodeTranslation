#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

string s;
int d,n,z;
ll dp[10001][101][2];
ll sol;

int main() {
    cin >> s >> d;
    n=s.size();
    dp[0][0][0]=1;
    for (int i=1;i<=n;i++) {
        for (int j=0;j<d;j++) {
            for (int k=0;k<10;k++) {
                for (int b=0;b<2;b++) {
                    if (k>(s[i-1]-'0') && b==0) {continue;}
                    int b2=b;
                    if (k<(s[i-1]-'0')) {b2=1;}
                    dp[i][(j+k)%d][b2]+=dp[i-1][j][b];
                    dp[i][(j+k)%d][b2]%=MOD;
                }
            }
        }
    }
    sol=(dp[n][0][0]+dp[n][0][1])%MOD;
    sol--;
    if (sol==-1) {sol=MOD-1;}
    cout << sol << endl;
}

