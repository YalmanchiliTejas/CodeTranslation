#include<iostream>
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int n, a[100009], ans;
multiset<int> st;
int main()
{
    IO
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        auto it=st.lower_bound(x);
        if(it==st.begin())
            ans++, st.insert(x);
        else
        {
            it--;
            st.erase(it);
            st.insert(x);
        }
    }

    cout<<ans;
}
