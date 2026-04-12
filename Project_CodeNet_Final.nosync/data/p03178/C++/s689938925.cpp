#include<bits/stdc++.h>
#define int long long
#define double long double
#define vi vector<int>
#define vpi vector<pair<int,int> >
#define mii map<int,int>
#define mpi map<pair<int,int>,int>
#define msi map<string,int>
#define set set<int>
#define u_set unordered_set<int>
#define pb push_back
#define endl "\n"
#define ll long long int
#define vll vector<long long int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define umap unordered_map 
#define mod 1000000007
#define fori(a,n) for(int i=a;i<n;i++)
#define forj(a,n) for(int j=a;j<n;j++)
#define MAX 300303
#define V vector
using namespace std;
int k,d;
int dig = 0;
vector<int> knum(10001);
V<vvi> dp(10001,vvi(101,vi(2,-1)));
int rec(int place, int sum, int tt){
    if(place == dig) return sum==0;
    if(dp[place][sum][tt] != -1)return dp[place][sum][tt];
    dp[place][sum][tt] = 0;
    if(tt){
        for(int digit=0;digit<knum[place];++digit){
            // if((sum+digit)%d==0)dp[place][sum][tt] += 1;
            dp[place][sum][tt] += (rec(place+1,(sum+digit)%d,0)+mod)%mod;
        }
        // ==knum[place]
        // if((sum+knum[place])%d==0)dp[place][sum][tt] += 1;
        dp[place][sum][tt] += (rec(place+1,(sum+knum[place])%d,1)+mod)%mod;
    }
    else{
        for(int digit=0;digit<10;++digit){
            // if((sum+digit)%d==0)dp[place][sum][tt] += 1;
            dp[place][sum][tt] += (rec(place+1,(sum+digit)%d,0)+mod)%mod;
        }
    }
    return (dp[place][sum][tt]+2*mod)%mod;
}
signed main()
{
    io
    // cin >> k >> d;
    int tt = 1;
    string kstr;
    cin >> kstr;
    cin >> d;
    for(int i=0;i<kstr.size();++i){
        knum[i] = kstr[i] - '0';
    }
    // int kk = k;
    // while(kk>0){
    //     knum.pb(kk%10);
    //     kk  /= 10;
    //     dig++;
    // }
    // reverse(knum.begin(),knum.end());
    // for(int i=0;i<knum.size();++i)cout << knum[i] << endl;
    dig = kstr.size();
    cout << (rec(0,0,1)-1+mod)%mod << endl;

} 