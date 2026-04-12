#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep2(i,a,b) for (int i = (a); i < (b); ++i)


int main() {
    int x;
    cin>>x;

    string ans;
    if(x==3 || x==5 || x==7) ans = "YES";
    else ans = "NO";

    cout<<ans<<endl;
        
    return 0;
}
