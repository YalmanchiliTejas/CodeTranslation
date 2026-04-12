#include <bits/stdc++.h>
using namespace std;

long long p_num(int l){
    if(l == 0) return 1;
    return p_num(l-1) * 2 + 1;
}
long long pb_num(int l){
    if(l == 0) return 1;
    return pb_num(l-1) * 2 + 3;
}

long long p[51], pb[51];
long long countp(int l, long long x){
    if(l == 0) return 1;
    if(x == 1) return 0;
    if(1 < x && x <= 1 + pb[l-1]) return countp(l-1, x-1);
    if(x == 2 + pb[l-1]) return p[l-1] + 1;
    if(2 + pb[l-1] < x && x <= 2 + pb[l-1] * 2) return p[l-1] + 1 + countp(l-1, x-2-pb[l-1]);
    else return 1 + p[l-1] * 2;
}

int main(){
    for(int i = 0; i <= 50; i++){
        p[i] = p_num(i);
        pb[i] = pb_num(i);
    }

    int n;
    long long x;
    cin >> n >> x;
    cout << countp(n, x) << endl;
}