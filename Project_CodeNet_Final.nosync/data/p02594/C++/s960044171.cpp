#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <climits> // FOO_MAX, FOO_MIN
#include <cmath> 
#include <cstdlib> // abs(int)
#include <numeric>
#include <iomanip>
#include <map>

using namespace std;

#define roundup(n,d) ( ((n) + ((d)-1)) / (d) )
#define assign_max(into, compared) (into = max((into), (compared)))
#define assign_min(into, compared) (into = min((into), (compared)))
#define rep(i,n) for(long long i = 0;i < n;++i)
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);
#define fix(n) fixed << setprecision(n)
#define ALL(v) v.begin(),v.end()

#define PI 3.14159265358979323846;

using ll = long long;
using ull = unsigned long long;
using vll = vector<long long>;


int main(void){
    FAST_IO
    
    ll x;
    cin >> x;
    if(x >= 30){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}