#include<bits/stdc++.h>
using namespace std;

int main(void){
    long long n, x, p[51], sub[51], sou[51];
    cin >> n >> x;
    long long cnt=0;
    p[0] = 1;
    p[1] = 3;
    sub[0] = 1;
    sub[1] = 2;
    sou[0] = 1;
    sou[1] = 5;
    for(int i=2;i<=n;++i){
        p[i] = p[i-1]*2+1;
        sub[i] = p[i-1]+1;
        sou[i] = sou[i-1]*2+3;
    }
    while(n>=0){
        if((sou[n]+1)/2 <= x){
            cnt+=sub[n];
            x -= (sou[n]+1)/2;
        }else{
            --x;
        }
        if(n > 1 && x<=n-1) break;
        --n;
    }
    cout << cnt << endl;
}