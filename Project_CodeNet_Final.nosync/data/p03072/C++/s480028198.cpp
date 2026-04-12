#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
    int n;
    cin >> n;
    vector<int>v(n,0);
    for(int i=0;i<n;i++)cin >> v[i];
    int cnt=1;
    for(int i=1;i<n;i++)
    {
        if(v[i]<v[i-1]){
            v[i]=v[i-1];continue;
        }
        cnt++;
    }
    cout<<cnt<<"\n";
    
}
