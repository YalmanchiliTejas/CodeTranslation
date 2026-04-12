#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <complex>
#include <cmath>
using namespace std;

vector<long long> ss,ps;

long long solve(long long n, long long x){
    if(n==0){
        return x;
    }
    if(x <= 1){
        return 0;
    }
    if(x <= ss[n-1]+1){
        return solve(n-1,x-1);
    }
    if(x == ss[n-1]+2){
        return ps[n-1] + 1;
    }
    if(x <= 2*ss[n-1]+2){
        return ps[n-1] + 1 + solve(n-1, x - 2 - ss[n-1]);
    }
    return ps[n];
}

int main(int argc, char const *argv[]) {
    long long n,x;cin>>n>>x;
    ss = vector<long long>(n+1);
    ps = vector<long long>(n+1);
    ss[0] = 1;
    ps[0] = 1;
    for(int i=0;i<n;++i){
        ss[i+1] = ss[i]*2 + 3;
        ps[i+1] = ps[i]*2 + 1;
    }
    cout<<solve(n,x)<<endl;
    return 0;
}