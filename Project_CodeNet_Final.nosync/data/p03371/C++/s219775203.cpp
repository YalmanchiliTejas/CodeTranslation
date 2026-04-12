#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <set>
#include <sstream>
#include <bitset>
#include <stack>
#include <cstdlib>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

typedef long long ll;

using namespace std;

int main() {
    
    ll a,b,c,x,y;
    
    cin >> a >> b >> c >> x >> y;
    
    ll ans=0;
    
    if(a+b >= 2*c){
        if(x>=y){
            if(a>2*c){
                ans = 2*c*x;
            }else{
                 ans = 2*y*c + (x-y)*a;
            }
        }else{
            if(b>2*c){
                ans = 2*c*y;
            }else{
                ans = 2*x*c + (y-x)*b;
            }
        }
    }else{
        ans = a*x+b*y;
    }
    
    cout << ans << endl;
    
    return 0;
}
