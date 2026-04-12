#include<bits/stdc++.h>
using namespace std;

#define sync {ios_base ::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);}
#define ll long long int
#define mod 1000000007

ll n;
int x,m;

void solve()
{
    cin>>n>>x>>m;
    
    vector<ll> ans;
    
    ans.push_back(x%m);
    
    ll sum = ans.front();
    
    ll i = 1;
    
    for(;i<m;i++)
    {
        ll x = pow(ans.back(),2);
        ll y = x%m;
        if(y==0)
        {
            cout<<sum;
            return;
        }

        sum += y;
        
        if(i==n-1)
        {
            cout<<sum;
            return;
        }
        
        ans.push_back(y);
        
        //cout<<y<<" ";
    }
    
    ll x = pow(ans.back(),2);
    ll y = x%m;
    if(y==0)
    {
        cout<<sum;
        return;
    }
    
    ll sum1 = 0;
    
    for(i = 0;i<ans.size();i++)
    {
        if(ans[i]==y)
        {
            break;
        }
        else
            sum1 += ans[i];
    }
    
    ll cyclelen = (m-i);
    
    ll cyclefac = floor((n-i)/double(cyclelen));
    
    ll rem =(n-i)%cyclelen;
    
    ll res = sum1 + (sum-sum1)*(cyclefac);
    
    
    for(ll j = i+1;j<i+1+rem;j++)
        res += ans[j-1];
    
    
    cout<<res;
    
    
}

int main()
{
    sync;
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
        cout<<"\n";
    }
    return 0;
}





