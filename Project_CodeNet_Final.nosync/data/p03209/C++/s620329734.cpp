#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <map>
 
using namespace std;

#define repd(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  repd(i,0,n)

vector<long long> a(1,{1});
vector<long long> p(1,{1});

long gcd(long a, long b) {
 	if ( a % b == 0 ) return b;
 	return gcd(b, a%b);
 }

map<long, int> prime_factor(long n) {
    map< long, int > ret;
    for(long i = 2; i * i <= n; i++) {
        while(n % i == 0) {
            ret[i]++;
            n /= i;
        }
    }
    if(n != 1) ret[n] = 1;
    return ret;
}

void buger(int level){
    // cout << level << endl;
    if (level == 0) {
        a.push_back(a.back()+1);
        return;
    }
    a.push_back(a.back());
    buger(level-1);
    a.push_back(a.back()+1);
    buger(level-1);
    a.push_back(a.back());
}

long f(int n, long x){
    if (n == 0) {
        return x <= 0 ? 0 : 1;
    }else if(x <= 1+ a[n-1]){
        return f(n-1, x-1);
    }else{
        return p[n-1] + 1 + f(n-1, x-2-a[n-1]);
    }
}

int main () {
    int n;
    long x;
    cin >> n >> x;
    rep(i,n){
        a.push_back(a[i]*2 + 3);
        p.push_back(p[i]*2 + 1);
    }
    cout << f(n,x) << endl;
    return 0;
}