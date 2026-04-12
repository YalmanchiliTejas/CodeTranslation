#include <bits/stdc++.h>
using namespace std;
#define int           long long
#define pb            push_back
#define mp            make_pair
#define PI            3.14159265
#define M             1000000007
#define MM            998244353
#define fr            first
#define sc            second
#define all(v)        (v).begin(),(v).end()
#define rall(v)       (v).rbegin(),v.rend()
#define vc            vector
#define vi            vector<int>
#define pii           pair<int,int>
#define psi           pair<string,int>
#define pis           pair<int,string>
#define mii           map<int,int>
#define msi           map<string,int>

int solve(){
    int n,s=0; cin>>n;
    int h[n];
    for (int i = 0; i < n; ++i)
    {
        cin>>h[i];
    }
    for (int i = 0; i < n; ++i)
    {
        int flag=1;
        for (int j = 0; j < i; ++j)
        {
            if(h[i]<h[j]){
                flag=0;
            }
        }
        if(flag) s++;
    }
    cout<<s;
}

signed main() {
    ios::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}