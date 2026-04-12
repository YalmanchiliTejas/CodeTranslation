#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;

int main(){
    int r,g,b;
    cin>>r>>g>>b;
    int ans = 100*r+10*g+b;
    puts(ans%4==0 ? "YES":"NO");
    return 0;
}
