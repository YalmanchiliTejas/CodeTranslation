#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
const int MOD=1e9+7;
#ifndef HOME
#define cerr if(0)cerr
#endif

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int c=1;
    int x=a[0];
    for(int i=1;i<n;i++){
        if(a[i]>=x){
            c++;
            x=a[i];
        }
    }
    cout<<c<<endl;
    return 0;
    
}

