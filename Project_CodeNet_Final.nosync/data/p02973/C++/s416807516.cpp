#include<bits/stdc++.h>
#include<string>
using namespace std;
#define int long long
#define pb push_back
#define mod 1000000007



int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &x:arr)
        cin>>x;
    // int ans=0;
    // stack<int> st;
    multiset<int> st;
    // st.push(-1);
    // st.clear();
    int ans=0;
    for(auto x:arr)
    {
        if(st.empty())
        {
            st.insert(x);
            continue;
        }
        auto it=st.lower_bound(x);
        if(it==st.begin())
        {
            st.insert(x);
            continue;
        }
        it--;
        st.erase(it);
        st.insert(x);
       // ans=max(ans, (int)st.size());
    }
    // if(st.size())
    //     ans++;
    cout<<st.size();
    return 0;
}