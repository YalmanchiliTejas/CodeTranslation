/*
░░░░░░░░░░░░░░░░▄▄█▀▀██▄▄░░░░░░░
░░░░░░░░░░░░░▄█▀▀░░░░░░░▀█░░░░░░
░░░░░░░░░░░▄▀░░░░░░░░░░░░░█░░░░░
░░░░░░░░░▄█░░░░░░░░░░░░░░░█░░░░░
░░░░░░░██▀░░░░░░░▄▄▄░░▄░█▄█▄░░░░
░░░░░▄▀░░░░░░░░░░████░█▄██░▀▄░░░
░░░░█▀░░░░░░░░▄▄██▀░░█████░██░░░
░░░█▀░░░░░░░░░▀█░▀█▀█▀▀▄██▄█▀░░░
░░░██░░░░░░░░░░█░░█░█░░▀▀▄█▀░░░░
░░░░█░░░░░█░░░▀█░░░░▄░░░░░▄█░░░░
░░░░▀█░░░░███▄░█░░░░░░▄▄▄▄█▀█▄░░
░░░░░▀██░░█▄▀▀██░░░░░░░░▄▄█░░▀▄░
░░░░░░▀▀█▄░▀▄▄░▄░░░░░░░███▀░░▄██
░░░░░░░░░▀▀▀███▀█▄░░░░░█▀░▀░░░▀█
░░░░░░░░░░░░▄▀░░░▀█▄░░░░░▄▄░░▄█▀
░░░▄▄▄▀▀▀▀▀█▀░░░░░█▄▀▄▄▄▄▄▄█▀▀░░
░▄█░░░▄██▀░░░░░░░░░█▄░░░░░░░░░░░
█▀▀░▄█░░░░░░░░░░░░░░▀▀█▄░░░░░░░░
█░░░█░░░░░░░░░░░░░░░░░░█▄░░░░░░░
*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define dbg(x) cout << #x << '=' << x << '\n';
#define ll long long
#define x first
#define y second
#define pi pair <int, int>
#define vi vector <int>
//#define =1e9 =(int)1e9
const ll mod = 1000000007;
const ll nmax=3000001;
#define int ll
int n, dp[101][2][2], d; /// prima ii daca toate cifrele is karoce ca sa vezi daca mai mare, a doua pentru transit
string s;

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    cin>>s>>d;
    dp[0][1][0]=1;

    for(int i=1; i<=s.size(); i++){
        int x=s[i-1]-'0';
        for(int md=0; md<=d-1; md++) dp[md][0][1]=dp[md][1][1]=0;
       // cout<<"XD "<<(7<x);
        for(int md=0; md<=d-1; md++){
            for(int c=0; c<=9; c++){
                //if(c==7)  cout<<"XD "<<(c<x);
                dp[((md+c)%d)][0][1]+=(dp[md][0][0]+dp[md][1][0]*(c<x));
                dp[((md+c)%d)][0][1]%=mod;
                //cout<<"xd"<<dp[((md+c)%d)][0][1];
            }
            dp[(md+x)%d][1][1]+=dp[md][1][0];
            dp[(md+x)%d][1][1]%=mod;
        }
        for(int md=0; md<=d-1; md++) dp[md][0][0]=dp[md][0][1], dp[md][1][0]=dp[md][1][1];// cout<<md<<" "<<dp[md][0][0]<<" "<<dp[md][1][0]<<endl;
    }
    cout<<(dp[0][1][0]+dp[0][0][0]+mod-1)%mod;
}
