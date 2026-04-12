#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n,mx=0,h;
    cin>>n;
    int ans=0;
    while (n--) {
        cin>>h;
        if (mx<=h) {
            mx=h;
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}