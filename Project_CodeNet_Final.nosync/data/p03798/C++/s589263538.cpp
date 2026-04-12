#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set> 
#include <map>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iomanip>
#define rep(i,n) for(int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1001001001; // > 10^9
const int MOD = (int)1e9 + 7;
const ll INFLL = 1001001001001001001;  // > 10^18
const ll MODLL = (ll)1e9 + 7;
const double EPS = 1e-9;

int main () {
    
    int n; cin >>n;
    string s; cin >>s;

    vector<int> sw;
    sw.push_back(1);
    sw.push_back(-1);

    vector<int> instance;
    bool flag = false;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            
            vector<int> t(n, 0);
            t[0] = sw[i];
            t[1] = sw[j];
            
            for (int k = 1; k < n-1; k++) {
                if (s[k] == 'o') {
                    t[k+1] = t[k]*t[k-1];
                } else {
                    t[k+1] = (-t[k])*t[k-1];
                } 
            }
            if (s[n-1] == 'o' && t[0] == t[n-1]*t[n-2]) {
                if (s[0] == 'o' && t[1] == t[0]*t[n-1]) {
                    flag = true;
                    instance = t;
                } 
                if (s[0] == 'x' && t[1] == (-t[0])*t[n-1]) {
                    flag = true;
                    instance = t;
                }
            } 
            if (s[n-1] == 'x' && t[0] == (-t[n-1])*t[n-2]) {
                if (s[0] == 'o' && t[1] == t[0]*t[n-1]) {
                    flag = true;
                    instance = t;
                } 
                if (s[0] == 'x' && t[1] == (-t[0])*t[n-1]) {
                    flag = true;
                    instance = t;
                }
            } 
        }
    }

    if (flag) {
        for (int i = 0; i < n; i++) {
            if (instance[i] == 1) {
                cout << "S";
            } else {
                cout << "W";
            } 
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    } 
    
    return 0;
}

