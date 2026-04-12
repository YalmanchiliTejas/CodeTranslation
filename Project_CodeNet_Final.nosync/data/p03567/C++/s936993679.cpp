#include <bits/stdc++.h>
using namespace std;
#define equals(a, b) (fabs((a) - (b)) < EPS)

typedef long long ll;
typedef pair < int , int > Pi;

const int INF = 1 << 28;
const ll LLINF = 1LL << 60;
const double EPS = 1e-9;

int main()
{
    bool flag = false;
    string S;
    cin >> S;
    for(int i = 0; i < S.size() - 1; i++) {
        if(S[i] == 'A' && S[i + 1] == 'C') {
            flag = true;
        }
    }
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return (0);
}