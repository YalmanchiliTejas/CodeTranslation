#include <bits/stdc++.h>
 
using namespace std;
#define repr(i,a,b) for (int i=a; i<b; i++)
#define rep(i,n) for (int i=0; i< (int) n; i++)
 
 
int main () {
    int r,g,b;

    cin >> r >> g >> b;

    if((100*r + 10*g + b) % 4 == 0)cout << "YES" << endl;
    else cout << "NO" <<  endl;


}

    
