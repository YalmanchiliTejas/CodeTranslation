#include <bits/stdc++.h> 
using namespace std;
#define rep(i, N) for(int i=0; i<N; i++)
typedef long long ll;
#define dump(x) cerr<<#x<<"="<<x<<endl
using P = pair<int, int>;

int main() {
    string s; cin >> s;
    if(s.at(1)=='A'&&s.at(2)=='A'&&s.at(0)=='A') {
        cout << "No" << endl;
        return 0;
    }
    if(s.at(1)=='B'&&s.at(2)=='B'&&s.at(0)=='B') {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    return 0;
}
