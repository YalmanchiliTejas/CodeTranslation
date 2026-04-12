#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define dbg          cout<<"Freak"<<endl;
#define dbgg(i)      cout<<i<<endl;
#define N            1e9+7
#define pb           push_back
#define pi           acos(-1)ll m=998244353;
ll t;


string s;
ll one(ll a,ll b)
{
    ll c,d,e,f,i,j;
    a=a*9;
    a+=b;
    //cout<<a<<endl;
    return a;
}
ll two(ll a,ll k)
{
    ll b,c,d,e,f=0,g,i,j;
    //cout<<a<<' '<<k<<endl;
    e=s.size();
    for(i=k; i<e; i++)
    {
        b=s[i]-'0';
        if(b!=0)
            break;
    }
    //cout<<b<<endl;
    f+=one(e-i-1,b);
    if(i==e)f=0;
    //dbgg(f);
    d=a-1;
    d=d*(d-1);
    d/=2;
    //dbgg(d);
    f+=(d*81);
    //dbgg(f);
    a--;
    c=s[k-1]-'0';
    //cout<<c<<endl;
    c--;
    f+=(c*9*a);
    //dbgg(f);
    return f;
}


vector<ll>v;
int main()
{
    ll a,b,c,d,e,f,g,i,j;
    cin>>s>>a;
    f=0;
    b=s.size();
    if(b<a)
        cout<<'0'<<endl;
    else if(a==1)
    {
        b--;
        f=s[0]-'0';
        cout<<one(b,f)<<endl;
    }
    else if(a==2)
    {
        cout<<two(b,1)<<endl;
    }
    else
    {
        f=0;
        for(i=1; i<b; i++)
        {
            d=s[i]-'0';
            if(d!=0)
                break;
        }
        if(i!=b)
        {
            f+=two(b-i,i+1);
            //cout<<a-i<<' '<<i+1<<endl;
        }
        //cout<<f<<endl;
        c=s[0]-'0';
        c--;
        for(i=0;i<b-2;i++)
        {
            for(j=i+1;j<b-1;j++)
            {
                for(ll k=j+1;k<b;k++)
                {
                    if(k!=b-1)f+=729;
                    else f+=(81*c);
                }
            }
        }
        cout<<f<<endl;
}
return 0;
}
