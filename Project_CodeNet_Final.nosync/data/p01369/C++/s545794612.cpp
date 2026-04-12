#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=(0);(i)<(int)(n);++(i))
using ll = long long;

int main() {

    string r="qwertasdfgzxcvb", l="yuiophjklnm";
    string str;

    sort(r.begin(), r.end());
    sort(l.begin(), l.end());

    int rr=0, ll=0;
    int alp[30];
    rep(i, r.size()+l.size()) {
        if ( i == r[rr]-'a') {
            alp[i] = 1;
            rr++;
        }
        else {
            alp[i] = -1;
            ll++;
        }
    }

    while (true) {

        cin >> str;
        if (str == "#") break;

        int cnt=0, prev=alp[str[0]-'a'];
        for (int i=1; i<str.size(); ++i) {
            if (prev != alp[str[i]-'a']) {
                prev = alp[str[i]-'a'];
                cnt++;
            }
        }

        cout << cnt << endl;

    }

    return 0;
}