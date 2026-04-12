#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define VI vector<int>
#define lf(i,a,b) for(int i=a;i<=b;i++)
ll k,n;
ll fun(ll b)
    {   ll cnt=(n/b)*(b-k);
        if(n%b>=k)
        {   cnt+=(min(n%b+1,b)-k);
        }
        //cout<<b<<" "<<cnt<<endl;
        if(k==0)
            cnt--;
        return cnt;
    }
int main()
{   cin>>n>>k;
    ll cnt=0;
    lf(ind,k+1,n)
    {   cnt+=fun(ind);
    }
    cout<<cnt<<endl;
}