#include<bits/stdc++.h>
using namespace std;

/*******  All Required define Pre-Processors and typedef Constants *******/
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.rbegin(), cont.rend()
#define rep(i,n) for(int i=0; i<(n); ++i)
#define rep1(i,n) for(int i=1; i<=(n); ++i)
#define Dcout(a) cout << setprecision(20) << a << endl
#define MP make_pair
#define PB push_back
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
using ll = long long;
using PAIR = pair<int, int>;
using Graph = vector<vector<int>>;
const double pi=acos(-1.0);
#define debug cout << "line : " << __LINE__ << " debug" << endl
/****** Template of some basic operations *****/
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
/**************************************/

/******** User-defined Function *******/

/**************************************/

/********** Main()  function **********/
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    double a,b,c; cin >> a >> b >> c;
    int x,y; cin >> x >> y;

    double c2 = c*2;
    double ab = a+b;

    int nowx = 0, nowy = 0;

    int ans = 0;
    while(nowx < x || nowy < y){
        if(nowx < x && nowy < y){
            if(ab<c2){
                ans += ab;
                nowx++;
                nowy++;
            }else{
                ans += c2;
                nowx++;
                nowy++;
            }
        }else if(nowx < x){
            if(c2<a){
                ans += c2;
                nowx++;
                nowy++;
            }else{
                ans += a;
                nowx++;
            }
        }else if(nowy < y){
            if(c2<b){
                ans += c2;
                nowx++,nowy++;
            }else{
                ans += b;
                nowy++;
            }
        }
    }

    cout << ans << endl;
}
/********  Main() Ends Here *************/
