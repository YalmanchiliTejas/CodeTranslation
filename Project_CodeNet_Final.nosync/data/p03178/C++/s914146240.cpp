#include<bits/stdc++.h>
using namespace std;
const int MODULO=1e9+7;
string str;
int D;
long long dp[100005][105][2];

long long solve(int idx, int sum, bool flag){
    if(idx==str.length()) return sum==0;
    int dig = str[idx]-'0';
    if(flag) dig=9;
    long long &ret=dp[idx][sum][flag];
    if(~ret) return ret;
    ret=0;
    for (int i = 0; i <= dig; ++i)
    {
        bool ok=flag;
        if(i<dig) ok=1;
        ret +=solve(idx+1, (sum+i)%D, ok)%MODULO;
    }
    return ret%MODULO;
}

int main(){
    // freopen("out.txt","wt",stdout);
    // scanf("%s", &str);
    // scanf("%d", &D);
    cin>>str>>D;
    memset(dp, -1, sizeof dp);
    cout<<(solve(0,0,0)-1+MODULO)%MODULO<<endl;
    return 0;
}