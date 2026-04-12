/**
 *  author: said_v15
 *  created with web_programmer
**/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int ans=0;
    bool TrOrNot;
    for(int i=0;i<n;i++)
    {
        TrOrNot=true;
        for(int j=0;j<i;j++)
        {
            if(arr[j]>arr[i]) {TrOrNot=false; break;}
        }
        if(TrOrNot) ans++;
    }
    cout<<ans<<"\n";
    return 0;
}