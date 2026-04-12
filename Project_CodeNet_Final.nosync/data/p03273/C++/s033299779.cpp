#include<bits/stdc++.h>

using namespace std;

using ll = long long;
#define long long long

int main(void) {
    ll h, w;
    cin >> h >> w;
    vector<string> a(h);
    for(auto &l: a) cin >> l;

    vector<char> t(h), s(w);
    for(ll i=0; i<h; i++)
        for(ll j=0; j<w; j++)
            if(a[i][j] == '#')
                t[i] = s[j] = 1;

    for(ll i=0; i<h; i++, t[i] && (cout << endl))
        for(ll j=0; j<w; j++)
            if(t[i] && s[j])
                cout << a[i][j];
}
