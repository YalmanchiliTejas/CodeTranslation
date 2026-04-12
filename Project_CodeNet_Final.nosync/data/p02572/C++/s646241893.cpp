#define _GLIBCXX_DEBUG
#define LIM 1000000007
#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;
using i64 = int64_t;
using vi = vector<i64>;

int main(void){
    int n;
    cin >> n;
    vi a(n), s(n+1);
    for(i64 &x : a) cin >> x;
    for(int i=n-1; i>0; i--){
        s[i] = a[i] + s[i+1];
        if(s[i] >= LIM) s[i] %= LIM;
    }
    i64 sum = 0;
    for(int i=0; i<n-1; i++){
        sum += a[i] * s[i+1];
        if(sum >= LIM) sum %= LIM;
    }
    cout << sum << '\n';
    return 0;
}