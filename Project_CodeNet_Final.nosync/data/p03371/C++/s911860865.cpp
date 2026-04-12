#include <cstdio>
#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#define rep(i,n) for (int i=0;i<n;i++)
using ll = long long;
using namespace std;

void solve(){

}
int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;

    int ans = 0;
    int ans2=0;
    ans2=2*c*(max(x,y));

    if(x>y){
        ans+=a*(x-y);
        x = y;
    }
    else if(y > x){
        ans += b*(y-x);
        y = x;
    }

    if((a+b)>2*c){
        ans += x*2*c;
    }
    else{
        ans+= (a+b)*x;
    }

    cout << min(ans,ans2);

    

    return 0;
}