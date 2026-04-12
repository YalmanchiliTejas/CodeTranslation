#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pbk pop_back
#define mk_pr make_pair

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<string> vss;
typedef queue<int> qi;

const int MX = 123456;

int main() {
        ios_base :: sync_with_stdio(0); cin.tie(0);

        int a, b, c;
        cin >> a >> b >> c;
        a = a*100 + b*10 + c;

        if( a%4 == 0 ) cout << "YES" << endl;
        else cout << "NO" << endl;

        return 0;
}
