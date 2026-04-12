//Created by Kira

#include<bits/stdc++.h>
using namespace std;

#define IOS cin.sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define pii pair<int,int> 
#define pb push_back
#define vi vector<int> 
using ll = long long;

const int mod = 1e9 + 7;

ll pwr(ll a, ll b);
    
void add_self(int & a, int b){
    a += b;
    if(a >= mod)a-=mod;
}

int main(){
   IOS

   string s; cin>>s;

   int D; cin>>D; 

   int n = s.length();

   vector<vi> dp(D, vi(2));

   //dp[sum][sm_already] : the num of ways to choose digits so far
   //st the sum of digits modulo D is 'sum' and 
   //sm_already tells whether we already chose some digit smaller than K

   dp[0][0] = 1;

   for(int where = 0; where < n; ++where){
       vector<vi>new_dp(D, vi(2));
       for(int sum = 0; sum < D; ++sum){
           for(bool sm_already : {false, true}){
               for(int digit = 0; digit < 10; ++digit){
                   if(digit > s[where]-'0' and !sm_already){
                       break;
                   }
                   add_self(new_dp[(sum+digit)%D][sm_already or digit < s[where]-'0'],dp[sum][sm_already]);

               }
           }

       }
       dp = new_dp;
   }

   int ans = (dp[0][false] + dp[0][true])%mod;
   --ans;
   if(ans == -1)
    ans = mod-1;

    cout<<ans<<"\n";

    







}

ll pwr(ll a, ll b){
   a %= mod;	//Remove mod if not required
   ll res = 1;
   while(b > 0){
    if(b&1)
        res = res * a % mod;
        a = a * a % mod;
    b >>= 1;
    }

    return res;
}

