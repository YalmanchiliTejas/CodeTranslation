#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define INF 100000000


int keta(ll x)
{
    int count = 0;
    while(x)
    {
        x/=10;
        count++;
    }
    return count;
}

int main()
{
    /*ABC144 B
    int x;
    cin>>x;
    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=9;j++)
        {
            if(x==i*j)
            {
                cout<<"Yes"<<endl;
                return 0;
            }
        }
    }
    cout<<"No"<<endl;
    */
    /*ABC150 B
    int n;
    string s;
    cin>>n>>s;
    int count = 0;
    for(int i=0;i<n-2;i++)
    {
        if(s[i]=='A')
        {
           if(s[i+1]=='B')
           {
               if(s[i+2]=='C')
               {
                   count++;
               }
           }
        }
    }
    cout<<count<<endl;
    */

    /*ABC136 B
    int n;
    cin>>n;
    int count = 0;
    for(int i=1;i<=n;i++)
    {
        int even=0;
        int num = i;
        while(num)
        {
            num/=10;
            even++;
        }
        if(even%2!=0)
        {
            count++;
        }
    }
    cout<<count<<endl;
    */
    /*ABC106 B
    int n;
    cin>>n;
    int count=0;
    for(int i=10;i<=n;i++)
    {
        int num = i;
        int yakusu=0;
        for(int j=1;j<=num;j++)
        {
            if(j%2==0)
            {
                continue;
            }
            if(num%j==0)
            {
                yakusu++;
            }    
        }
        if(yakusu==8)
        {
            count++;
        }
    }    
    cout<<count<<endl;
    */
    /*ABC120 B
    int a,b,k;
    cin>>a>>b>>k;
    int count=0;
    for(int i=100;i>=1;i--)
    {
        if(a%i==0 && b%i==0)
        {
           count++;
        }
        if(count==k)
        {
            cout<<i<<endl;
            return 0;
        }
    }
    */
    /*ABC057 C
    ll n;
    cin>>n;
    int ans = keta(n);
    for(ll i=1;i*i<=n;i++)
    {
        int cur=0;
        if(n%i==0)
        {
            ll b = n/i;
            cur = max(keta(i),keta(b));
        }
        else continue;

        if(cur<ans)
        {
            ans = cur;
        }
    }

    cout<<ans<<endl;
    */

    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    int ab=2*c;
    int cost = a*x+b*y;
    for(int i=0;i<=100000;i++)
    {
        int temp=0;
        temp +=i*ab+max(x-i,0)*a+max(y-i,0)*b;
        cost = min(temp,cost);
    }
    cout<<cost<<endl;
    return 0;
}