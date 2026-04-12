#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
const ll LL_MAX=LLONG_MAX;

struct In{
    template<typename T>
    operator T(){
        T x;
        cin >> x;
        return x;
    }
};
In in;

template <typename T,typename U>
void forin(T* x,U n){
    for (U i=0;i<n;i++) cin >> x[i];
}

template <typename T>
int div1(T x) {
    return x%1000000007;
}

template <typename T>
void out(T x){
    cout << x << endl;
}

template <typename T>
T gcd(T x,T y){
    if (y == 0) return x;
    return gcd(y,x%y);
}

template <typename T>
T lcm(T x,T y){
    return x*y/gcd(x,y);
}

int main(){
 int n=in,m=in;
  if (n == m) out("Yes");
  else out("No");
}