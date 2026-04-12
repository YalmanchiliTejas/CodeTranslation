#include<bits/stdc++.h>
#define int long long int
#define endl "\n"
#define arrinp(v) for(auto &i:v) cin>>i;
#define arrout(v) for(auto &i:v) cout<<i<<" ";
#define newline cout<<endl;
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t=1;
    // cin >> t;
    while (t--) {
        int n;
        cin>>n;
        if(n>=30){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}