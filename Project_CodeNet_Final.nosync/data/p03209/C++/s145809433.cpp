#include <iostream>
#include <algorithm>

using namespace std;

long wid[51], pathe[51];

long rec(int l, long x){
    if(x == 0) return 0;
    if(l == 0) return 1;
    long ans = 0;
    ans += pathe[l-1] * (x / (wid[l-1]+1));
    if(x > wid[l-1] + 1) ans++;
    long rest;
    if(x / (wid[l-1]+1) == 0) rest = x-1;
    if(x / (wid[l-1]+1) == 1) rest = max(0l, x-2-wid[l-1]);
    if(x / (wid[l-1]+1) == 2) rest = 0;
    return ans + rec(l-1, rest); 
}

int main(){
    long N, X;
    cin >> N >> X;
    wid[0] = 1; pathe[0] = 1;
    for(int i=1; i<=N; i++){
        wid[i] = wid[i-1] * 2 + 3;
        pathe[i] = pathe[i-1] * 2 + 1;
    }
    cout << rec(N, X) << endl;
    return 0;
}