#include <bits/stdc++.h>
#define all(a) (a).begin(), (a).end()
#define REP(i, n) for(int (i)=0; (i)<(n); (i)++)
#define RREP(i, n) for(int (i)=(n)-1; (i)>=0; (i)--)
#define ios() cin.tie(0), ios::sync_with_stdio(false)
typedef long long ll;
typedef unsigned long long ull;
ll const MOD = 1e9+7;
ll const INF = 1e18;
using namespace std;

int main(){
    vector<char> v = {'a', 'i', 'u', 'e', 'o'};
    char c;
    cin >> c;
    cout << (find(all(v), c) != v.end() ? "vowel" : "consonant") << endl;
    return 0;
}