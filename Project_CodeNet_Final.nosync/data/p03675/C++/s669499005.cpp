#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t,n,i,j,k,x;
    cin>>n;
    vector<ll>vi;
    for(i = 0 ;i<n ;i++)
    {
        cin>>x;
        vi.push_back(x);
    }
    if(n%2 ==0)
    {
        for(i = n-1 ;i>=0 ;i-=2)
            cout<<vi[i]<<" ";
        for(i = 0 ;i<n ;i+=2)
            cout<<vi[i]<<" ";
        cout<<endl;
    }
    else
    { for(i = n-1 ;i>=0 ;i-=2)
            cout<<vi[i]<<" ";
             for(i = 1 ;i<n ;i+=2)
            cout<<vi[i]<<" ";
            cout<<endl;

    }
    return 0 ;
}

