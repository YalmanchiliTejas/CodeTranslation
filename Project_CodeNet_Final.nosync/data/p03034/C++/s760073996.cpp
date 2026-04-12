#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> v;
    v.resize(n);
    for(int i=0;i<n;++i)  cin>>v[i];
    long long maxn=0;
    for(int i=1;i<n;++i)
    {
        long long m=0;
        for(int l=0,r=n-1;l+i<n-1;l+=i,r-=i)
        {
            if((n-1)%i==0&&l>=r) break;
            m+=0ll+v[l]+v[r];
            if(maxn<m) maxn=m;
        }
    }
    cout<<maxn;
    return 0;
}