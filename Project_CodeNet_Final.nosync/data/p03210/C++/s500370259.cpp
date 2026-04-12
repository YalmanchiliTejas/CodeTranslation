#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;
template<typename T>
void print(T x) {
    cout << x << endl;
}
int main(void) {
    int x; cin >> x;
    if((x-3)*(x-5)*(x-7) == 0 ) print("YES");
    else print("NO");
}

