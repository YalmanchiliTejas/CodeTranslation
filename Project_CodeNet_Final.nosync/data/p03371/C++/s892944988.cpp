#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T>
using vec = std::vector<T>;

int main() {
    int A,B,AB,X,Y;
    cin >> A >> B >> AB >> X >> Y;
    int a = A*X+B*Y;
    int b = X*AB*2 + max(Y-X,0)*B;
    int c = Y*AB*2 + max(X-Y,0)*A;
    cout << min({a,b,c}) << endl;
}