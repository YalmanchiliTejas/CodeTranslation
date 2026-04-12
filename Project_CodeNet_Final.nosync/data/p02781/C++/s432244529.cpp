#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<int, int>
#define PP pair<P,P>
using namespace std;
int dp[105][4][2];

int main(){
    string s; cin >> s;
    int k; cin >> k;
    int sl=s.length();
    dp[0][0][0]=1;

    rep(i,sl)rep(j,4)rep(p,2){
        int now=s[i]-'0';
        rep(d,10){
            int nj=j; int np=p;
            if(d!=0) nj++;
            if(nj>k) continue;
            if(d>now && p==0) continue;
            if(d<now) np=1;
            dp[i+1][nj][np]+=dp[i][j][p];
        }
    }
    cout << dp[sl][k][0]+dp[sl][k][1] << endl;
return 0;
}
