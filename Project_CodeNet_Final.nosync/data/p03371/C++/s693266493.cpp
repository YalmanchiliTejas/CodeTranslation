#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T>
using vec = std::vector<T>;

int main() {
    ll A,B,AB,X,Y;
    cin >> A >> B >> AB >> X >> Y;
    
    if(A+B<2*AB){
        cout << A*X + B*Y << endl;
    } else if(X>=Y){
        ll pat1 = max(X,Y)*AB*2;
        ll pat2 = min(X,Y)*AB*2 + (X-Y)*A;
        cout << min(pat1,pat2) << endl;
    } else {
        ll pat1 = max(X,Y)*AB*2;
        ll pat2 = min(X,Y)*AB*2 + (Y-X)*B;
        cout << min(pat1,pat2) << endl;
    }
}
