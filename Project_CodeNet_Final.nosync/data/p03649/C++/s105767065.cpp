#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <cmath>
#include <list>
#include <chrono>
#include <thread>
#include <thread>
#include <fstream>

using namespace std;

//const bool debug = false;

#ifndef M_PI
    const double M_PI = acos(-1.0);
#endif // M_PI

#define y1 roman_kaban
#define rank oryshych_konb
#define ull unsigned long long
//#define ll long long
const int mod = int(1e9) + 7;
//const int inf = 1e7;
//const long long infLL = 1e16;
//const int MX2 = 10100500; //  e7
//const long long INF = 1e18 + 0.5;
const int MX = 100500; //       e6
const int SZ = 122;

long long a[MX];
int n;


int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("/Users/ozzy/Documents/in.txt","r", stdin);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    long long ans = 0;
    while(true){
        bool ok = true;
        for(int i = 0 ; i < n; i++){
            if(a[i] < n) ok = false;
        }
        if(ok) break;
        int pos = 0;
        for(int i = 0; i < n; i++){
            if(a[i] > a[pos]) pos = i;
        }
        if(a[pos] <= n - 1){cout << ans << endl; return 0;}
        a[pos] -= n + 1;
        for(int i = 0; i < n; i++){
            a[i]++;
        }
        ans++;
    }
    for(int i = 0; i < n; i++){
        long long extra = a[i] - (n - 1);
        long long z = extra / (n + 1);
        //if(extra % n < z) z--;
        //extra -= z;
        //z = extra / n;
        ans += z + n * z;
        a[i] -= z + n * z;
    }
    while(true){
        int pos = 0;
        for(int i = 0; i < n; i++){
            if(a[i] > a[pos]) pos = i;
        }
        if(a[pos] <= n - 1){cout << ans << endl; return 0;}
        a[pos] -= n + 1;
        for(int i = 0; i < n; i++){
            a[i]++;
        }
        ans++;

    }
    return 0;
}
