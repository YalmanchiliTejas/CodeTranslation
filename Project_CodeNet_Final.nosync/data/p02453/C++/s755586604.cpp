#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>a;
    for(int i = 0;i<n;i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }
    int t,k,r;
    cin>>t;
    for(int i = 0;i<t;i++)
    {
       cin>>k;
      r =  lower_bound(a.begin(),a.end(),k)-a.begin();
      cout<<r<<endl;
    }
    return 0;
}

