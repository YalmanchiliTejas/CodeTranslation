/*
      author : nishi5451
      created: 11.08.2020 00:45:38
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int r,g,b;
    cin >> r >> g >> b;
    if( (10*g+b)%4 == 0 ) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}