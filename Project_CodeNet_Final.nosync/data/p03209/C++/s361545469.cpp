#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;

vector<ll> a,p;

ll rec(int n,ll x){
    if(n == 0){
        if(x <= 0) return 0;
        else return 1;
    }else if(x <= 1 + a[n-1]){
        return rec(n-1,x-1);
    }else {
        return p[n-1] + 1 + rec(n-1,x-2-a[n-1]);
    }
}

int main(){
    int n;
    ll x;
    cin >> n >> x;
    a.resize(n+1);
    p.resize(n+1);
    a[0] = 1;
    p[0] = 1;
    reps(i,1,n+1){
        a[i] = 2*a[i-1] + 3;
        p[i] = 2*p[i-1] + 1;
    }

    cout << rec(n,x) << endl;
    return 0;
}
