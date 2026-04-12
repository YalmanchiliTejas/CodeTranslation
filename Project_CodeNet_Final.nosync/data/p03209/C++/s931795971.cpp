#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

int n, x; 
int a[60];
int p[60];

int f(int n, int x){
    if(n==0){
        if(x<=0) return 0;
        else return 1;
    }
    if(x<=a[n-1]+1) return f(n-1, x-1);
    if(x==a[n-1]+2) return p[n-1] + 1;
    if(x<=2*a[n-1]+1) return p[n-1] + 1 + f(n-1, x-a[n-1]-2);
    else return 2*p[n-1] + 1;
}

signed main(){
    cin >> n >> x;
    a[0] = 1;
    p[0] = 1;
    for(int i=1; i<=n; ++i){
        a[i] = 2*a[i-1] + 3;
        p[i] = 2*p[i-1] + 1;
    }
    cout << f(n, x) << endl;

    return 0;
}