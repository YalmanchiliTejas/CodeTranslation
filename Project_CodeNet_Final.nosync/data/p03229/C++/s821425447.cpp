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
    multiset<int>s;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s.insert(a[i]);
    }
    sort(a+1,a+n+1);
    int ans=0;
    int mx=0;

    if(n%2==0)
    {
        int x=a[n/2];
        s.erase(s.find(x));
        while (!s.empty())
        {
            auto j=s.end();
            j--;
            ans+=abs(*j-x);
            x=*j;
            s.erase(j);
            if(!s.empty())
            {
                j=s.begin();
                ans+=abs(*j-x);
                x=*j;
                s.erase(j);
            }
        }    
        mx=max(mx,ans);    
    }
    else
    {
        int x=a[(n+1)/2];
        s.erase(s.find(x));
        while (!s.empty())
        {
            auto j=s.end();
            j--;
            ans+=abs(*j-x);
            x=*j;
            s.erase(j);
            if(!s.empty())
            {
                j=s.begin();
                ans+=abs(*j-x);
                x=*j;
                s.erase(j);
            }
        }
        mx=max(mx,ans);                
    }
    for(int i=1;i<=n;i++)
        s.insert(a[i]);
    ans=0;
    if(n%2==0)
    {
        int x=a[n/2+1];
        s.erase(s.find(x));
        while (!s.empty())
        {
            auto j=s.begin();
            ans+=abs(*j-x);
            x=*j;
            s.erase(j);
            if(!s.empty())
            {
                j=s.end();
                j--;
                ans+=abs(*j-x);
                x=*j;
                s.erase(j);
            }
        }    
        mx=max(mx,ans);    
    }
    else
    {
        int x=a[(n+1)/2];
        s.erase(s.find(x));
        while (!s.empty())
        {
            auto j=s.begin();
            ans+=abs(*j-x);
            x=*j;
            s.erase(j);
            if(!s.empty())
            {
                j=s.end();
                j--;
                ans+=abs(*j-x);
                x=*j;
                s.erase(j);
            }
        }
        mx=max(mx,ans);                
    }

    cout<<mx;    
} 