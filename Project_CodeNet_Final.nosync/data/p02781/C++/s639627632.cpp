#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <deque>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <unordered_map>
#include <bitset>
#include <sstream>

typedef  long long ll;
#define mop 1000000007
using namespace std;

unsigned long long nCr(long n, long r) {
    unsigned long long ans = 1;
    for (long i = 1 ; i < r + 1; ++i) {
        ans = ans * (n-i+1)/ i;
    }
    return ans;
}
ll ans = 0;
string s;
ll idx = 0;
void solve(ll k, bool stat, ll p){
//    cout << ans << endl;
//    cout << "solve " << k << " " << stat << " " << p << " called" << endl;
    if(stat == false){
        if(p < 0 or k < p)
            return;
        ans += (ll)(pow(9, p)) * nCr(k,p);
        return;
    }
    if(k==0){
        if(p == 0)ans++;
//        ans++;
        return;
    }
    ll a = s[idx] - '0';
    for(ll i=1;i<a;i++){
        solve(k-1, false, p-1);
    }
    if(a != 0){
        solve(k-1, false, p);
        idx++;
        solve(k-1, true, p-1);
    }else{
        idx++;
        solve(k-1, true, p);
    }
}

int main() {
   

    ll c;
    cin >> s >> c;
    solve(s.length(), true, c);
    cout << ans << endl;

}