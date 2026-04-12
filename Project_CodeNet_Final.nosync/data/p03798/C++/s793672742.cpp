#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool try_sw(bool t0, bool t1, int N, const vector<bool> &ox){
    vector<bool> sws(N + 1, false);
    string SW = "SW";
    sws[0] = t0;
    sws[1] = t1;
    for (int i = 1; i < N; ++i) sws[i + 1] = ox[i] xor (sws[i] xor sws[i - 1]);
    if ((sws[0] == sws[N]) and (sws[N - 1] == ox[0] xor (t0 xor t1))){
        for (int i = 0; i != N; ++i) cout << SW[int(sws[i])];
        cout << endl;
        return true;
    }
    return false;
}

int main() {
    int N;
    string S;
    cin >> N;
    cin >> S;
    vector<bool> ox(N, false);
    for (int i = 0; i < N; ++i) ox[i] = (S[i] == 'x');
    for (int i = 0; i != 4; ++i){
        bool t0 = i / 2 > 0;
        bool t1 = i % 2 > 0;
        if (try_sw(t0, t1, N, ox)) return 0;
    }
    cout << -1 << endl;
    return 0;
}
