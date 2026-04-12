#include<iostream>
#define mod 1000000007
#define DIM 200005
using namespace std;
int n, m, i, k, nr, sol;
char s[DIM];
int d[DIM], sum[DIM];
int main(){
    cin>> n >> m;
    cin>> s + 1;
    k = m;
    for(i = 1; i <= m; i++){
        if(s[i] == s[1]){
            nr++;
        }
        else{
            if(nr == i - 1){
                if(nr % 2 == 1){
                    k = min(k, nr);
                }
                else{
                    k = min(k, nr + 1);
                }
            }
            else{
                if(nr % 2 == 1){
                    k = min(k, nr);
                }
            }
            nr = 0;
        }
    }
    sum[1] = d[1] = 1;
    if(k == m){
        sum[2] = 1;
        for(i = 3; i < n; i++){
            d[i] = sum[i - 2];
            sum[i] = (d[i] + sum[i - 1]) % mod;
        }
        sol = 1;
        for(i = 1; i < n; i++){
            sol = (sol + d[n - i] * 1LL * (i + 1) ) % mod;
        }
        cout<< sol;
        return 0;
    }
    for(i = 3; i < n; i += 2){
        d[i] = sum[i - 2];
        if(i - k - 3 > 0){
            d[i] -= sum[i - k - 3];
            if(d[i] < 0){
                d[i] += mod;
            }
        }
        sum[i] = d[i] + sum[i - 2];
        if(sum[i] >= mod){
            sum[i] -= mod;
        }
    }
    for(i = 1; i < min(n, k + 2); i += 2){
        sol = (sol + d[n - i] * 1LL * (i + 1) ) % mod;
    }
    cout<< sol;
}
