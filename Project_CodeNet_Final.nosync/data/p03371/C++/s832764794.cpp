#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <utility>
#include <iomanip>  // std::setprecision()
using namespace std;
using ll = long long;
#define rep(i,a,b) for(int i=(a); i<(b); i++)
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define yes cout << "Yes" << endl;
#define no cout << "No" << endl;
ll gcd(ll a, ll b){if (a%b == 0)  return(b);else  return(gcd(b, a%b));}
ll lcm(ll a, ll b){return a * b / gcd(a, b);}
/* map<string,int> */
/* 大文字を小文字に変換 tolower*/
/* 小文字を大文字に変換 toupper*/
/* 辞書順 next_permutation(a.begin(),a.end()) */
 
int main() {
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    int mi  = 100000;
    int ans = 0;
    if ((a +b) > c*2) {
        mi = min(mi,x);
        mi = min(mi,y);
        x -= mi;
        y -= mi;
        mi = mi *2;
        ans += mi*c;
    }
    if (a < 2*c) {
       ans += a*x; 
    } else {
        ans += (2*c) *x;
    }
    if (b <2*c) {
        ans += b*y;
    } else {
        ans += (2*c) * y;
    }
    cout << ans << endl;

}