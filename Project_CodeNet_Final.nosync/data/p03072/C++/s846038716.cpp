#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    //w   e
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    int ans=0;
    for(int i=0; i<n; i++){
        bool flag=false;
        for(int j=0; j<i; j++){
            if(a[j] > a[i]) flag = true;
        }
        ans+=(flag? 0 : 1);
    }
    cout<<ans;
    return 0;
}