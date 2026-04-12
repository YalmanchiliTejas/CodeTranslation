#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, s, n) for (int i = s; i < (int)(n); i++)
#define inpv(i, n, v) rep(i,n) do {int tmp; cin>>tmp; v.push_back(tmp);} while(0)
#define outv(i,n,v) rep(i,n) cout << v[i] << endl

void Main() {
    char a,b,c;
    cin >> a >> b >> c;
    if (a == b && b == c) {
        cout << "No";
    } else cout << "Yes";
    /*
    vector<int> v;
    inpv(i,n,v);
    */
}


int main() {
    Main();
    return 0;
}