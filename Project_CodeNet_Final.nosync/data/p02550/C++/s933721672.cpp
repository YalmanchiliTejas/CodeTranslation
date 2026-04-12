#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n,x,m;
    cin>>n>>x>>m;
    long long ans=0;
    long long prev=x;
    unordered_map<long long,int> st;
    vector<long long> vec;
    vec.push_back(0);
    int mark=1e9;
    for(int i=1;i<=n;i++)
    {
        //cout<<prev<<endl;
        if(st.find(prev)==st.end())
        {
            st.insert({prev,i});
            vec.push_back(prev);
            prev=(prev*prev)%m;
        }
        else
        {
            mark=st[prev];
            break;
        }
    }
    mark=min(mark,(int)vec.size());
    for(int i=1;i<mark;i++)
    {
        ans=ans+vec[i];
    }
    int len=vec.size()-mark;
    if(len>0)
    {
        long long cycleSum=0;
        for(int i=mark;i<vec.size();i++)
        {
            cycleSum+=vec[i];
        }
        n=n-(mark-1);
        ans=ans+(n/len)*cycleSum;
        for(int i=mark;i<=(n%len)-1+mark;i++)
        {
            ans+=vec[i];
        }
    }
    cout<<ans<<"\n";
    return 0;
}