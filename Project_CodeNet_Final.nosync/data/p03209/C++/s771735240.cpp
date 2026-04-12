#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>
#include <cmath>
#include <cstdio>

using namespace std;

long long num_patty(int n){
    long long t=pow(2, n+1);
    return t-1;
}

long long num_total(int n){
    long long t=pow(2, n+2);
    return t-3;
}

long long f(int n, long long x){
    if(x==0) return 0;
    if(x==num_total(n)) return num_patty(n);
    long long t=num_total(n-1);
    if(x<t+2) return f(n-1, x-1);
    if(x>t+2) return f(n-1, x-t-2)+num_patty(n-1)+1;
    else return num_patty(n-1)+1;
}

int main(){
    int n; cin >> n;
    long long x; cin >> x;
    cout << f(n, x) << endl;
    return 0;
}
