#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define pb push_back
#define w(x) int x; cin>>x; while(x--)
#define f(i,n) for(ll i=0;i<n;i++)
#define f1(i,n) for(ll i=1;i<=n;i++)
#define ff first
#define ss second
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define me max_element
const int mod = 1e9 + 7;

void ganekasar() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void add_self(ll& a, ll b)
{
    a += b;

    if(a > mod)
        a -= mod;
}

int main() 
{
    string k;
    cin>>k;

    ll D;
    cin>>D;

    ll len = k.length();

    vvi dp(D, vi(2));

    dp[0][0] = 1;

    for(int here=0; here<len; here++)
    {
        vvi new_dp(D, vi(2));

        for(int sum=0; sum<D; sum++)
        {
            for(bool sm_already : {false, true})
            {
                for(ll digit=0; digit<10; digit++)
                {
                    if(digit > k[here] - '0' && !sm_already)
                        break;

                    add_self(new_dp[(sum+digit)%D][sm_already || (digit < k[here] - '0')], dp[sum][sm_already]);
                }
            }
        }

        dp = new_dp;
    }    

    ll answer = (dp[0][false] + dp[0][true])%mod;

    answer--;

    if(answer == -1)
        answer = mod-1;

    cout<<answer<<endl;

    return 0;
}
