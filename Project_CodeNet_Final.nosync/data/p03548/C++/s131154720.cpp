#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep2(i,a,b) for (int i = (a); i < (b); ++i)

#define INF 100000000




int main(){
    int x,y,z;
    cin>>x>>y>>z;

    x -= z;
    int ans = 0;

    while(x>=y+z){
        x -= y + z;
        ans++;
    }

    cout << ans << endl;

    return 0;
}