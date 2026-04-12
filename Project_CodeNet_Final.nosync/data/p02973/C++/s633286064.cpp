#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int N=2e5+5;
int a[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,ans=0;
    multiset<int>st;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=n-1;i>=0;i--)
    {
        auto it=st.upper_bound(a[i]);
        if(it==st.end())
            ans++;
        else st.erase(it);
        st.insert(a[i]);
    }
    cout<<ans<<endl;
    return 0;
}
