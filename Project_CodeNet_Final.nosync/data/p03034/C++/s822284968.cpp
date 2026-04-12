#include<iostream>
#include<vector>
using namespace std;

template<class T> inline bool chmax(T& a, T b){ if(a < b){ a = b;return 1;}return 0;}
template<class T> inline bool chmin(T& a, T b){ if(a > b){ a = b;return 1;}return 0;}

main()
{
    int n;cin>>n;
    typedef long long ll;
    vector<ll> s(n);
    for(int i=0;i<n;i++)cin>>s[i];
    ll res=0;
    for(int p=1;p<=n-1;p++)
    {
        if((n-1)%p==0)
        {
            ll tmp=0;
            ll cur=0;
            int i=0,j=n-1;
            for(;i<j;i+=p,j-=p)
            {
                cur+=s[i]+s[j];
                chmax(tmp,cur);
            }
            chmax(res,tmp);
        }
        else
        {
            ll tmp=0;
            ll cur=0;
            int i=0,j=n-1;
            for(;i<n-1&&j>p;i+=p,j-=p)
            {
                cur+=s[i]+s[j];
                chmax(tmp,cur);
            }
            chmax(res,tmp);
        }
        
    }
    cout<<res<<endl;
    return 0;
}