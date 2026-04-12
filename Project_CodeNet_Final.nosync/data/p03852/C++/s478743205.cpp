#include<bits/stdc++.h>

#define fi first
#define se second
#define FO(x, n) for (int x = 0; x < n; ++x)
#define FOR(x, a, b) for (int x = a; x < b; ++x)
#define RFO(x, n) for (int x = n - 1; x >= 0; --x)
#define RFOR(x, a, b) for (int x = b - 1; x >= a; --x)
#define FOR_ITER(x, a) for(auto x = a.begin(); x != a.end(); ++x)



using namespace std;
typedef unsigned char byte;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<string, string> pss;
typedef pair<ll, ll> pll;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < 1e-10; }

using namespace std;


int main(){
//    int n, l;
//    cin >> n >> k;
//    vector<bool> dislike(10, false);
//
//    FOR(i, 0, k) {
//        int t;
//        cin >> t;
//        dislike[t] = true;
//    }

    char a, b, c;
    cin >> a ;//>> b >> c;

    cout << (a=='a'||a=='e' ||a=='i'||a=='o'||a=='u'? "vowel":"consonant") << endl;

    return 0;
}
