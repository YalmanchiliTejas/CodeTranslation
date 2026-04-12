/*|In The Name Of Allah|*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 3e3+5;
const int mod = 998244353;

int n;
int sm;
int ar[N];
int mem[N][N];

int go(int idx , int sum){
    if(sum == sm){
        return n - idx + 2;
    }
    if(sum > sm || idx > n){
        return 0;
    }
    if(~mem[idx][sum]){
        return mem[idx][sum];
    }
    int a = go(idx + 1 , sum + ar[idx]);
    int b = go(idx + 1 , sum);
    return mem[idx][sum] = (a + b) % mod;
}

int main(){
    cin >> n >> sm;
    for(int i = 1; i <= n; i++){
        cin >> ar[i];
    }
    memset(mem , -1 , sizeof mem);
    int ways = 0;
    for(int i = 1; i <= n; i++){
        ways += go(i , 0);
        ways %= mod;
    }
    cout << ways << "\n";
}
