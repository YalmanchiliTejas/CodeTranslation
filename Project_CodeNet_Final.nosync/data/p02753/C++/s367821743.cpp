#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 1; i <= (int)(n); i++)

int main(){
    set<char> s;
    rep(i, 3){
        char tmp;
        cin >> tmp;
        s.insert(tmp);
    }
    if (s.size() == 2) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
