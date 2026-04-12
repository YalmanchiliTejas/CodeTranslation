#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define foi(i,n) for(int i = 0; i < n ; ++i)
#define pi pair<int,int>
#define pb push_back
#define debug cout << "here" << endl;
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;

int dp[10001][101][2];

int solve(string &s,int D,int d,int pos,bool tight){
   int answer =0 ;
   int ub = tight==1?(s[pos]-'0'):9;
   if(pos == s.length()-1){
        for(int i = 0 ;i <= ub ; i++) if(i%D==d) answer = (answer +1)%mod;
        return answer;
   }

   if(dp[pos][d][tight]!=-1) return dp[pos][d][tight];



   for(int i = 0 ; i <= ub ; i++){
        bool newTight = (tight&&(i==ub));
        answer = (answer%mod + solve(s,D,(D+d-(i%D))%D,pos+1,newTight)%mod)%mod;
   }

   return dp[pos][d][tight] = (answer%mod);
}




int32_t main(){
    memset(dp,-1,sizeof(dp));
    string k;int d;
    cin >> k >> d;
    cout << (solve(k,d,0,0,1) - 1+mod)%mod;
}
