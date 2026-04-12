#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,x;
    vector<long long int>v,b;
    cin>>n;
    for(long long int i=0; i<n; i++)
    {
        cin>>x;
        if(i%2==0)
            v.push_back(x);
        else
            b.push_back(x);
    }
    if(n%2==0)
    {

        reverse(b.begin(),b.end());
        for(long long int i=0; i<b.size(); i++)
        {
            cout<<b[i]<<" ";
        }
        for(long long int i=0; i<v.size(); i++)
        {
            cout<<v[i]<<" ";
        }

        cout<<endl;
    }
    else
    {
        reverse(v.begin(),v.end());
        for(long long int i=0; i<v.size(); i++)
        {
            cout<<v[i]<<" ";
        }
        for(long long int i=0; i<b.size(); i++)
        {
            cout<<b[i]<<" ";
        }

        cout<<endl;
    }
    return 0;
}
