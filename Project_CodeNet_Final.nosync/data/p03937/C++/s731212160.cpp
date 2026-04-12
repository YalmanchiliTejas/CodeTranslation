/**
*    author:  souzai32
*    created: 02.08.2020 15:36:30
**/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {

    int h,w;
    cin >> h >> w;
    char a;
    int count=0;
    rep(i,h*w){
        cin >> a;
        if(a=='#') count++;
    }

    if(count==h+w-1) cout << "Possible" << endl;
    else cout << "Impossible" << endl;

    return 0;
}