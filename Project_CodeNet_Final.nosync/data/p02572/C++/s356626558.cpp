#include <bits/stdc++.h>

using namespace std;

const int mxn = 2e5 + 10;
const int Mod = 1e9 + 7;

long long Ans = 0, s = 0;
int arr[mxn];

int main()
{
    ios::sync_with_stdio(false);

    int n;
    cin>>n;
    for(int i=0 ; i<n ; i++){
        cin>>arr[i];
        s+=arr[i];
    }

    for(int i=0 ; i<n ; i++){
        s-=arr[i];
        Ans += (((s%Mod)*1LL*(arr[i]%Mod))%Mod);
        Ans%=Mod;
    }
    cout<<Ans<<endl;

    return 0;
}
