#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:108777216")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("fast-math")
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <bitset>
#include <queue>
#include <deque>
#include <utility>
#include <algorithm>
#include <ctime>
using namespace std;
 
int const MAX_N = 256 * 1024;
 
int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
 
    int n,k;
    cin>>n>>k;
    
    long long ans = 0;
    for (int b = k+1; b<=n; b++) {
        long long cnt_full = n / b;
        ans += cnt_full * (b-k);
        if (k == 0) ans--;
        long long rem = n % b;
        if (k <= rem)
            ans += rem-k+1;
            
        //cout<<"B = "<<b<<" "<<ans<<"\n";
    }
     //   for (int a = k; a <= n; a += b) {
            
       //     cout<<"("<<a<<","<<b<<")  ";
         //   ans++;
    //    }
    cout<<ans;
    return 0;
}  
