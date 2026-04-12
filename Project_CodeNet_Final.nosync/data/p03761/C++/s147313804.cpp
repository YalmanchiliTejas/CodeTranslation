#include <algorithm>
#include <iostream>
#define REP(i, n) for (int i = 0; i < n; ++i)
using namespace std;

int N, m[26][50];
int main(){
    cin >> N;
    REP(i,N) {
        string s;
        cin >> s;
        for (char c: s) {
            m[c - 'a'][i]++;
        }
    }
    REP(i,26) {
       int me = *min_element(m[i], m[i] + N);
       while (me--) cout << (char)('a' + i);
    }
    return 0;
}