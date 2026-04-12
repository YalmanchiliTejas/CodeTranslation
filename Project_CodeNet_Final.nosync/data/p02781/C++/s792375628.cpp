#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[102][102];
string s;
int k;
int p[4]={1,9,81,729};
int cal(string s, int k) {
    //cout <<"s=" << s <<" k=" << k <<endl;
    if (s.size()<k)
        return 0;

    if (s.size()==0)
        return k==0;
    if (s[0]=='0')
        return cal(s.substr(1,s.size()-1),k);

    int ans = 0;
    string x(s.size()-1,'9');

    ans +=  cal(x,k);
    for (char c='1'; c<s[0];c++) {
        ans += dp[s.size()-1][k-1]*p[k-1];
    }
    ans += cal(s.substr(1,s.size()-1),k-1);
    return ans;
}
int main(){

    dp[0][0] = 1;
    for (int i=1;i<=101;i++){
        dp[i][i]=dp[i][0] = 1;
        for (int j=1;j<=3;j++)
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        //for (int j=0;j<=3;j++)
        //    printf("%d ",dp[i][j]);
        //printf("\n");
    }

    while (cin>>s) {
        scanf("%d",&k);
        printf("%d\n",cal(s,k));
    }
    return 0;
}
