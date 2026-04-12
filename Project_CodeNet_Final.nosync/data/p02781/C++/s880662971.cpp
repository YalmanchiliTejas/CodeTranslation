#include <bits/stdc++.h>
 #define rep(i,a,b) for (int i=a;i<b;i++)
 #define rep2(i,a,b) for (int i=a;i>=b;i--)
 #define mod 1000000007
 #define INF  1e9+5
 #define f first
 #define se second
 #define endl '\n'
 #define ll long long
 #define ii pair <int,int>
 #define pll pair <ll,ll>
 #define vi vector <int>
 #define vl vector <ll>
 #define vvi vector < vi >
 #define vii vector < ii >
 #define vvii vector < vii >
 #define vll vector < ll >
 #define mi map<int,int>
 #define mll map<ll,ll>
 #define mci map<char,int>
 #define msi map<string,int>
 #define vb  vector <bool>
 #define pb push_back
 #define mk make_pair
 #define sz(a) a.size()
 #define all(a) a.begin(),a.end()
 #define rall(a) a.rbegin(),a.rend()
 #define Senky_Bansal ios_base::sync_with_stdio(false);
#define IIIT_ALLAHABAD    cin.tie(NULL);cout.tie(NULL);
using namespace std;
vector<int>v;
ll dp[110][2][110];
string s;
ll k;
int solve(int idx,int flag,int sum)
{ 
    if(idx>=v.size() and flag==1)
    {
        if(sum==k)
            return 1;
        else
            return 0;
    }
    if(idx>=v.size()) return 0;
    if(dp[idx][flag][sum]!=-1)
        return dp[idx][flag][sum];
    ll ans=0;
    if(flag==1)
    {   
        for(int i=0;i<10;i++)
        {
            int x;
            if(i!=0)
            x = solve(idx+1,1,sum+1);
        else
            x = solve(idx+1,1,sum);
            //if(x.se==1)
            ans=(ans+x);
            //else ans+=x.f;
        }
    }
    else
    {
        for(int i=0;i<10;i++)
        {
            if(v[idx]>i)
            {
                int x;
                if(i!=0)
            x = solve(idx+1,1,sum+1);
        else
            x = solve(idx+1,1,sum);
            //if(x.se==1)
            ans=(ans+x);
                //else ans+=x.f;
            }
            else if(v[idx]==i)
            {
                int x;
                if(i!=0)
            x = solve(idx+1,0,sum+1);
           else
            x = solve(idx+1,0,sum);
            //if(x.se==1)
            ans=(ans+x);
            }
            else break;
        }
    }
    return dp[idx][flag][sum]=ans;
}
 signed main()
 {
    Senky_Bansal
    IIIT_ALLAHABAD
     
    
            cin>>s;
            cin>>k;
            memset(dp,-1,sizeof dp);
            v.clear();
            for(int i=0;i<s.size();i++)
            {
                int p1 = int(s[i])-48;
                v.pb(p1);
            }
            ll z=0;
          //  cout<<"Se"<<endl;
            if(v.size()!=0)
            z=solve(0,0,0);
            //cout<<"se"<<endl;
           ll count=0;
           for(int i=0;i<s.size();i++)
           {
             int p1 = int(s[i])-48;
             if(p1!=0) count++;
           }
           if(count==k) z++;
            cout<<z<<endl;
}