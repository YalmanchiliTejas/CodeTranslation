#include <bits/stdc++.h>

using namespace std;


#ifdef CLION

ifstream ifs("/home/kyuridenamida/CLionProjects/untitled4/input.txt");
#define cin ifs
#define scanf DONT_USE_SCANF
#endif

typedef long long ll;


int main() {
    int n;
    cin >> n;
    deque<int> Q;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        Q.push_back(x);
    }
    sort(Q.begin(), Q.end());
    deque<int> V;
    V.push_back(Q.back());
    Q.pop_back();

    long long ans = 0;
    while (Q.size()) {
        vector<pair<int, pair<int, int>>> C;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                int q = i ? Q.front() : Q.back();
                int x = j ? V.front() : V.back();
                C.push_back({abs(q - x), {i, j}});
            }
        }
        sort(C.begin(), C.end());
        ans += C.back().first;
        int I = C.back().second.first;
        int J = C.back().second.second;
        int q = I ? Q.front() : Q.back();
        if (J) {
            V.push_front(q);
        } else {
            V.push_back(q);
        }
        if (I) {
            Q.pop_front();
        } else {
            Q.pop_back();
        }
    }
    cout << ans << endl;
}

