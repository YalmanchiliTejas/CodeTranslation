#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define PI acos(-1.0)
#define mod 1e9+7
using namespace std;
vector<int>v;
int main()
{
    int n, sz=1;
    cin>>n;
    int x;
    cin>>x;
    v.pb(x);
    for(int i=1; i<n; i++)
    {
        //int x;
        cin>>x;
        if(x<=v[sz-1])
        {
            v.pb(x);
            sz++;
            continue;
        }
        int st=0, end=sz-1;
        while(st<end)
        {
            int mid=(st+end)/2;
            if(v[mid]>=x) st=mid+1;
            else end=mid;
        }
        v[st]=x;
    }
    cout<<v.size()<<endl;
    return 0;
}
