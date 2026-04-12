#include <iostream>
#include<cstdlib>
#include<queue>
#include<set>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<stack>
#include<map>
#include<deque>
#include<cstdio>
#include<cstdio>
using namespace std;
#define rep(i,a) for(int i=0;i<a;i++)
#define mp make_pair
#define pb push_back
#define ll __int64
#define __int64 long long
#define P pair<int,int>
#define PP pair<P,int>

string s;
ll n;
ll k;
ll dp[200][2][5];//dp[桁][未満][0の個数]=パターン
ll keta[200];
int main(){
    cin>>s>>k;
    int n=s.size();
    rep(i,n)keta[i]=s[i]-'0';

    dp[0][0][0]=1;

    for(int i=0;i<n;i++){
        for(int smaller=0;smaller<2;smaller++){
            for(int cnt=0;cnt<=k;cnt++){
                for(int x=0;x<=(smaller?9:keta[i]);x++){
                    if(x!=0)dp[i+1][smaller || x < keta[i]][cnt+1] += dp[i][smaller][cnt];
                    else dp[i+1][smaller || x < keta[i]][cnt] += dp[i][smaller][cnt];
                }
            }
        }
    }

    cout<<dp[n][0][k]+dp[n][1][k]<<endl;
    return 0;
}
