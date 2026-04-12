#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <random>
#include <chrono>
#include <queue>
#include <math.h>
#include <string>
#include <sstream>
#include <stack>
 
using namespace std;
 
#define ll long long
#define rep(i,n) for(ll i=0;i<n;i++)

int main(){
    ll a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    ll ans=1e18;
    
    rep(i,max(x,y)+1){//セット買う個数
        ll ans1=0;
        ans1+=2*c*i;
        if(x-i>0) ans1+=  (x-i)*a;
        if(y-i>0) ans1+=  (y-i)*b;
        ans=min(ans,ans1);
    }
    cout << ans << endl;
}

