#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <iterator>
#include <iomanip>
using namespace std;

long long const mod = 998244353;


int main(){
    long long n, s;
    cin >> n >> s;
    vector<long long> a(n + 1);
    for(int i = 1; i <= n; ++i) cin >> a[i];

    vector<vector<long long> > d(n + 1, vector<long long>(s + 1));
    for(int i = 0; i <= n; ++i){
        d[i][0] = i + 1;
    }
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= s; ++j){
            if(a[i] <= j && d[i - 1][j - a[i]]){
                d[i][j] = (d[i - 1][j - a[i]] + d[i - 1][j]) % mod;
            }
            else if(d[i - 1][j]) d[i][j] = d[i - 1][j];
        }
    long long ans = 0;
    for(int i = 1; i <= n; ++i) ans = (ans + d[i][s]) % mod;
    cout << ans;
}