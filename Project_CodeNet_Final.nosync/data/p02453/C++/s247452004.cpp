#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) rep(i,0,n)

int main()
{
    int n,q;
    cin>>n;
    vector<int>a(n);
    REP(i,n)cin>>a[i];
    cin>>q;
    REP(i,q)
    {
        int k;
        cin>>k;
        cout<<lower_bound(a.begin(),a.end(),k)-a.begin()<<endl;
    }
}
