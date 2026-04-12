#include<bits/stdc++.h>
#include<vector>
#include <stdio.h>

using namespace std;

#define mod 1000000007LL
#define pi 3.141592653589793238462643383279;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define f first
#define s second


int main()
{
    int n,m;
    cin>>n>>m;
    set<pii> s;
    vector<int> v(n);
    for(int i=1;i<=n;i++)
        v[i-1]=i;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        s.insert({a,b});
        s.insert({b,a});
    }
    int ans=0;
    //while(next_permutation(v.begin()+1,v.end()))
    do
    {
        //cout<<"3423"<<endl;
        bool temp=true;
        for(int i=1;i<n;i++)
        {
            if(s.find({v[i],v[i-1]})==s.end())
                {
                    temp=false;
                    break;
                }
        }
        if(temp)
            ans++;
    }while(next_permutation(v.begin()+1,v.end()));
    cout<<ans<<endl;
    //int acc;cin>>acc;
    return 0;
}
