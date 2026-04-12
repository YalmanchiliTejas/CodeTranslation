#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long a[100], p[100];
long long f(int n, long long x){
    if(!n){
        if(x <= 0) return 0;
        else return 1;
    }
    if(x <= 1 + a[n-1]) return f(n-1, x-1);
    else return p[n-1] + 1 + f(n-1, x - 2 - a[n-1]);
}

int main(){
    int n; long long x; cin >> n >> x;
    for(int i = 0; i < n; i++){
        if(!i) a[0] = p[0] = 1;
        else{
            a[i] = 2 * a[i-1] + 3;
            p[i] = 2 * p[i-1] + 1;
        }
    }
    cout << f(n, x) << endl;
    return 0;
}
