#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)
#define REPi(i, a, b) for(int i=int(a); i<int(b); i++)
#define MEMS(a,b) memset(a,b,sizeof(a))
#define mp make_pair
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll MOD = 1e9+7;

int main(){
    bool a, b;
    a = false, b = false;
    REP(i,3){
        char c;
        cin >> c;
        if(c == 'A')
            a = true;
        else if(c == 'B')
            b = true;
    }

    if(a && b)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
