//----------------------------------------------------------------------
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
//----------------------------------------------------------------------
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(void) {
    string s; cin >> s;

    int tota= 0;
    int totb= 0;
    rep(i,(int)s.size()) {
       if(s[i] == 'A')
           tota++;
       else if(s[i] == 'B')
           totb++;
    }
    if(tota==3||totb==3)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
    return 0;
}
