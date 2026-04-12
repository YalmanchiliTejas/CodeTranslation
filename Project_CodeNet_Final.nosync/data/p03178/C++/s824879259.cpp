#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7;
const int N=10234;
char k[N];
int main(){
    scanf("%s",k);
    int d;
    cin>>d;
    ll len=strlen(k);
    vector<vector<int>>dp(d,vector<int>(2));
    dp[0][0]=1;
    for(int where=0;where<len;where++){
        vector<vector<int>>new_dp(d,vector<int>(2));
        for(int sum=0;sum<d;sum++){
            for(bool smaller:{true,false}){
                for(int digit=0;digit<10;digit++){
                    if(digit>(k[where]-'0')&&!smaller)
                        break;
                    new_dp[(sum+digit)%d][smaller||digit<(k[where]-'0')]=
                            (new_dp[(sum+digit)%d][smaller||digit<(k[where]-'0')]+dp[sum][smaller])%mod;


                }
            }
        }
        dp=new_dp;
    }
    cout<<(dp[0][0]+dp[0][1]-1+mod)%mod<<endl;
}
