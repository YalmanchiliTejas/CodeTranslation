
#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include <cmath>
#include<string.h>
#include <stdio.h>
#include <unordered_map>
#include <queue>
#include<climits>
#include <iomanip>



using namespace std;
#define ll long long
#define clr(x) memset(x, 0, sizeof(x))
#define tcase ll t;cin>>t;while(t--)
#define all(v) v.begin(),v.end()
#define GCJ ll t;cin>>t;for(ll H=1;H<=t;H++){cout<<"CASE #"<<H<<": ";solve();}
#define fast ios_base::sync_with_stdio(0);cin.tie(0)
#define endl "\n"
//comment out the above line when coding probs which require flushing the output



void solve()
{
    ll n;
    cin>>n;
    ll a[n];
    
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    
    ll dp[n][n];
    clr(dp);
    
    
    
    ll count = 0, add=0;
    while(count<(n*(n+1))/2)
    {
        for(ll i=0;i+add<n;i++)
        {
            ll j=i+add;
            if(i==j)
            {
                dp[i][j]=a[i];
            }
            else
            {
                dp[i][j]=max(a[i]-dp[i+1][j], a[j]-dp[i][j-1]);
                

            }
            
            
            count++;
        }
        add++;
    }
    
    

    
    cout<<dp[0][n-1]<<endl;
}


int main()
{
    
    
    fast;
    //tcase
    // {
    solve();
    // }
    
}




