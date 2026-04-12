#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    cin>>n;
    vector <long long> a(n);
    for(long long i=0;i<n;i++)
    {
        cin>>a[i];
    }
    long long q;
    cin>>q;
    for(long long i=0;i<q;i++)
    {
        long long k;
        cin>>k;
        cout<<lower_bound(a.begin(),a.end(),k)-a.begin()<<endl;
    }
    return 0;
}


