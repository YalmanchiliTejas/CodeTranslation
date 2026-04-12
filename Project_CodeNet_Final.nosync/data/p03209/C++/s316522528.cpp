#include<bits/stdc++.h>
using namespace std;
#define ll long long;
#define MM = 1000000000;
#define mod = MM + 7;
#define INF (ll)1e18
#define pi acos(-1.0)
#define MAX 1000000005
#define NIL -1
long long func(int n, long long x){
    if(n == 0){
        return 1;
    }if(x == 1){
        return 0;
    }if(1 < x && x < pow(2, 1+n) - 1){
        return func(n-1, x-1);
    }if(x == pow(2, 1+n) -1){
        return func(n-1, x-1) + 1;
    }if(x > pow(2, 1+n) - 1){
        return func(n-1, x-(pow(2, 1+n) -1)) + pow(2, n);
    }
}

int main(){
    int N; long long X; cin >> N >> X;
    cout << func(N, X) << endl;
}