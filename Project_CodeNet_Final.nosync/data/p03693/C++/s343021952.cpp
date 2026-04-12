#include <bits/stdc++.h>
#define rep(i,n) for(int (i) = 0; (i) < (n); ++(i))
#define _Pi 3.1415926535
using namespace std;
typedef long long ll;

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    int num = c;
    num += 10*b;
    num += 100*a;
    if(num % 4 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
