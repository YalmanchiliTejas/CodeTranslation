#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef pair<int, int> P;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

void YN(bool flg){if(flg) cout << "YES" << endl; else cout << "NO" << endl;}
void Yn(bool flg){if(flg) cout << "Yes" << endl; else cout << "No" << endl;}
void yn(bool flg){if(flg) cout << "yes" << endl; else cout << "no" << endl;}

int main()
{
    char h[] = {'a', 'i', 'u', 'e', 'o'};
    char c;
    cin >> c;

    bool ok = false;
    rep(i, 5) {
        if(c == h[i]) ok = true;
    }

    if(ok) {
        cout << "vowel" << endl;
    } else {
        cout << "consonant" << endl;
    }

    return 0;
}
