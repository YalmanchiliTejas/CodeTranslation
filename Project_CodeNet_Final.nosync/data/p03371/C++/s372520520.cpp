#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cassert>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <bitset>
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)

using namespace std;
typedef long long ll;
const ll MOD=1e9+7;

int main() {
    std::ios::sync_with_stdio(0); cin.tie(0);

    ll i,j,h;

    ll A,B,C,X,Y;
    vector<vector <char> > a(1, vector<char>(2));
    ll ans = 0;
  
    cin >> A>>B>>C>>X>>Y;

    ll min_=min(X,Y);

    vector<ll> n(2), m(2);
    n[0]=A;
    n[1]=B;
    ll x;

    if(X>Y)x=A;
    else x=B;

    if(A+B>2*C){
        ans += 2*C*min_;
        if(x>2*C)ans += 2*C*(max(X,Y)-min_);
        else ans += x*(max(X,Y)-min_);
    }else{
        ans += A*X+B*Y;
    }


  
    cout << ans<< endl;

    return 0;
}