#include <bits/stdc++.h>
using namespace std;
int main() {
    long long x,y,z;
    cin>>x>>y>>z;
     x-=2*z*1ll;
    vector<long long>valid;
    for(int i=1;i<=x;i++)
    {
        long long gap=(i-1)*1ll*z;
        if((x-i*1ll*y)>=gap)
        {
            valid.push_back(i);
        }

    }   
    sort(valid.begin(),valid.end(),greater<int>());
    cout<<valid[0];
}



