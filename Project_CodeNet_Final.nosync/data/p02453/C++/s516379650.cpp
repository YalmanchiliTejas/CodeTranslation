#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x,q,k;
    vector<int>v;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        v.push_back(x);
    }
    cin>>q;
    for(int i=0;i<q;i++)
    {
        cin>>k;
        vector<int>::iterator s;
        s=lower_bound(v.begin(),v.end(),k);
        cout<<s-v.begin()<<endl;
    }
    return 0;
}

