    #include<bits/stdc++.h> 
    using namespace std; 
    #define ll long long int
    #define fi first
    #define se second
    #define pb push_back
    #define mod 1000000007
    #define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll power(ll x, ll y, ll p)  
    {  
        ll res = 1;x = x % p;if (x == 0)return 0;while (y > 0)  
        {if (y & 1) res = (res*x) % p;  y = y>>1; x = (x*x) % p;  }  return res;  
    }
    bool sortinrev(const pair<vector<int>,int>&a,const pair<vector<int>,int>&b){if(a.fi==b.fi)return b.se>a.se;return a.fi>b.fi;}
    void run(vector<int>v){for(int i=0;i<v.size();i++)cout<<v[i]<<" ";cout<<endl;}
    void solve()
    {
        int n;
        cin>>n;
        ll a[n];ll sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
        // cout<<sum<<endl;
        ll table[n][n];
        for(int gap=0;gap<n;gap++)
        {
            for(int i=0,j=gap;j<n;++i,++j)
            {
                ll x = ((i+2)<=j)?table[i+2][j]:0;
                ll y = ((i+1)<=(j-1))?table[i+1][j-1]:0;
                ll z = ((i)<=(j-2))?table[i][j-2]:0;
                table[i][j] = max(a[i]+min(x,y),a[j]+min(y,z));
            }
        }
        cout<<2*table[0][n-1]-sum<<endl;


    }
    int main() 
    { 
       
        solve();
        
            
        
        
        return 0; 
    } 