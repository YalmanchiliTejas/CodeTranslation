#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
string s;
int n,k;
long long memo[101][4][3];
long long dp(int index,int num,bool ssf){
    if (num<0) return 0;
    if (num==0) return 1;
    if (index==n) return 0;
    if (memo[index][num][ssf]!=-1) return memo[index][num][ssf];
    long long largest=9,ans=0;
    if (ssf) largest=s[index]-'0';
    for (int i=0;i<=largest;i++){
        int cur=num;
        if (i!=0) cur--;
        ans+=dp(index+1,cur,ssf && i==largest);
    }
    return memo[index][num][ssf]=ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(memo,-1,sizeof(memo));
    cin>>s>>k;
    n=s.size();
    cout<<dp(0,k,true);
}