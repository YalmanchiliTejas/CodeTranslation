#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}


int main() {

int a,b,c;
cin >> a >> b >>c;

int num = 100*a + 10 *b +c;
if(num%4==0)cout << "YES" << endl;
else cout << "NO" << endl;
 
return 0;

}