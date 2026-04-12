#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pi 3.141592653589793238
#define int long long
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// mt19937 gen_rand_int(chrono::steady_clock::now().time_since_epoch().count());
// mt19937_64 gen_rand_ll(chrono::steady_clock::now().time_since_epoch().count());
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long power(long long a, long long b,long long m) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a %m;
        a = a * a %m;
        b >>= 1;
    }
    return res;
}

signed main()
{

ios_base::sync_with_stdio(false);
cin.tie(NULL);  
cout.tie(0);   

#ifndef ONLINE_JUDGE
    if(fopen("INPUT.txt","r"))
    {
    freopen ("INPUT.txt" , "r" , stdin);
    freopen ("OUTPUT.txt" , "w" , stdout);
    }
#endif  

    int n;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int l=0,r=8e17;
    int mn=1e18;
    while (l<=r)
    {
        int mid=l+(r-l)/2;
        bool flag=false;
        for(int j=max(mid-100,0LL);j<=mid+100;j++)
        {
            int temp[n+1];
            for(int i=1;i<=n;i++)
            {
                temp[i]=a[i]+j;
            }
            int tot=0;
            for(int i=1;i<=n;i++)
            {
                tot+=temp[i]/(n+1);
                temp[i]%=n+1;
                if(temp[i]==n)
                    tot++;
            }
            if(tot<=j)
            {
                flag=true;
                mn=min(mn,j);
            }
        }
        if(flag)
        {
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }        
    }
    cout<<mn;
    

} 
    
