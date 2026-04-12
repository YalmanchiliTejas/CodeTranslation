#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main(){
    // 制約見て！！！デカかったらlong longにすること！

    int x,y,z;
    cin >> x >> y >> z;
    x -= z;
    int ans = x/(y+z);
    cout<<ans<<endl;
}