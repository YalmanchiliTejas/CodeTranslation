#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    int h,w,count=0;
    cin>>h>>w;
    vector<string> a(h);
    rep(i,h) cin>>a[i];
    rep(i,h) {
        rep(j,w) {
            if (a[i][j]=='#') count++;
        }
    }
    if (count==(h+w-1)) cout<<"Possible"<<endl;
    else cout<<"Impossible"<<endl;
}
