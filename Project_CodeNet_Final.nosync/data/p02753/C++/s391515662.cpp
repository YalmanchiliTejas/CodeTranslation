#include <bits/stdc++.h>

using namespace std;

int32_t main() {

    ios_base::sync_with_stdio(false);

    cin.tie(0);

    string a;

    cin >> a;

    if(count(a.begin(),a.end(),'A')==1 or count(a.begin(),a.end(),'B')==1) {

        cout << "Yes" <<'\n';

    } else {

        cout << "No" <<'\n';

    }

    return 0;

}

