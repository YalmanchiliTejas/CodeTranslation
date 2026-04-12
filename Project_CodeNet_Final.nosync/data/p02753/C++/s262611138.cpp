#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

#define rep(i, a, b) for(auto (i)=a;i<b;i++)
#define list(i, N) for(auto (i)=0;i<N;i++)

typedef long long ll;
typedef vector <ll> vi;
typedef pair <ll, ll> pi;
#define mp make_pair
#define pb push_back
#define eb emplace_back

#define int ll
#define INF 1e18+5
#define mod 1000000007

template<class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s; cin >> s;
    bool containsA = false;
    bool containsB = false;
    for(auto c: s){
        if(c=='A') containsA = true;
        else containsB = true;
    }
    if(containsA && containsB){
        cout << "Yes\n";
    }else {
        cout << "No\n";
    }

    return 0;
}