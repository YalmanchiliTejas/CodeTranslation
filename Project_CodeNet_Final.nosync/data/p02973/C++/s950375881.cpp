#include<bits/stdc++.h>
using namespace std;
main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    multiset<int>st;
    multiset<int>::iterator itr;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int now=a[i];
        itr=st.upper_bound(-now);
       // cout<<"paise "<<*itr<<endl;
        if(itr!=st.end())
        {
            //cout<<"1st "<<endl;
            int ase=*itr;
            st.erase(itr);
            st.insert(-now);
        }
        else
        {
           // cout<<"2nd "<<endl;
            ans++;
            st.insert(-now);
        }
    }
    cout<<ans<<endl;
}
