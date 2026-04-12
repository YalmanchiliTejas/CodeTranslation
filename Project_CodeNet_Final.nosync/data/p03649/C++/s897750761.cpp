#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
const int maxn = 333;
const int lg = 22;
long long get(vector<long long> v){
    int len = v.size();
    long long ops = 0;
    while(true){
        long long sum = 0;
        vector<long long> add(len, 0);
        for(int e = 0; e < len; e++){
            long long now = v[e] / len;
            add[e] -= now;
            ops += now;
            sum += now;
        }
        for(int e = 0; e < len; e++){
            v[e] = (v[e] % len) + add[e] + sum;
        }
        bool ended = true;
        for(int e = 0; e < len; e++)
            ended &= v[e] < len;
        if(ended)
            break;
    }
    return ops;
}
int M(){
    int n;
    if(!~scanf("%d", &n)) return 0;
    vector<long long> iv(n);
    for(long long & t : iv) cin >> t;
    cout << get(iv) << endl;
    return 1;
}
int main(){
    while(M());
    return 0;
}
