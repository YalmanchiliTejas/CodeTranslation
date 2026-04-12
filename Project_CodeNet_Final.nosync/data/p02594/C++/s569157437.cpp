#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <queue>
#include <map>
#include <set>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#define in insert
#define er erase
#define fi first
#define se second
#define mp make_pair
#define all(x) x.begin(),x.end()
#define le(x) (int) x.length()
#define rsz resize

using namespace std;
typedef vector <int> vi;
typedef vector <vector <int> > vii;
typedef pair <int, int> pii;
typedef queue <int> qi;
typedef double db;
typedef long long ll;
typedef long double ld;
 
const long double PI=3.141592653589793238462643383279502884;
const long long PRIME1=1e9+787;
 
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
ll minll(ll a,ll b) {return a<=b?a:b;}
ll maxll(ll a,ll b) {return a>=b?a:b;}

int main () {
    fast;
    int t;
    cin>>t;
    if (t>=30) {
        cout<<"Yes";
        
    } else {
        cout<<"No";
    }
    return 0;
}
 
 
