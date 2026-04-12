#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int main(){
    int n;
    cin>>n;
    vector<int> h(n);
    for (int& i : h) cin >> i;
    int mh = h[0], r = 1;
    for (int i = 1; i < n; ++i)
        if (mh <= h[i]) mh = h[i], ++r;
    cout << r;
    return 0;
}