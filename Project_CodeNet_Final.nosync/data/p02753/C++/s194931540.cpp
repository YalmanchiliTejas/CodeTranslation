#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define LINF 1000000000000000000
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define bit(n) (1LL<<(n))
using namespace std;

typedef pair<int, int> P;
typedef pair<long long, long long> LLP;

int main() {

    string S;
    cin >> S;
    cout << (S[0] == S[1] && S[1] == S[2] ? "No" : "Yes") << endl;
    
    return 0;
}