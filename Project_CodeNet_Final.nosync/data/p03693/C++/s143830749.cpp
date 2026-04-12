#include <bits/stdc++.h> 
using namespace std;
#define rep(i, N) for(int i=0; i<N; i++)
typedef long long ll;
#define dump(x) cerr<<#x<<"="<<x<<endl

int main() {
    int r, g, b; cin >> r >> g >> b;
    int res = 100 * r + 10 * g + b;
    if(res%4==0){
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
}