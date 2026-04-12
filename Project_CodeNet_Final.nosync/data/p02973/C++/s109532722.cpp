#include<bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    multiset<int>s;
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    s.insert(a[n-1]);
    for(int i=n-2;i>=0;i--){
        auto it=s.lower_bound(a[i]+1);
        if(it==s.end()){
            // cout<<"coming\n";
            s.insert(a[i]);
            continue;
        }
        s.erase(it);
        s.insert(a[i]);
    }
    cout<<s.size()<<"\n";
}