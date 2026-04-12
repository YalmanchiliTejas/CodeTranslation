#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    int len = S.size();
    map<char, int>m;
    for (int i=0; i < len; i++) {
        if (m.count(S[i]) > 0) {
            m[S[i]] = m[S[i]] + 1;
        } else {
            m[S[i]] = 1;
        }
    }

    for (int i=1; i<N; i++) {
        string n;
        cin >> n;
        map<char, int> hikaku;
        int n_size = n.size();
        for (int j=0; j < n_size; j++) {
            if (m.count(n[j]) > 0) {
                if (hikaku.count(n[j]) > 0) {
                    hikaku[n[j]] = 1 + hikaku[n[j]];
                } else {
                    hikaku[n[j]] = 1;
                }
            }
        }

        for (const auto j: m){
            int count = hikaku[j.first];
            hikaku[j.first] = min(j.second, count);
        }

        m = hikaku;
    }

    vector<string>vec;
    for (const auto j:m) {
        int count = m[j.first];
        while (count > 0) {
            vec.emplace_back(string() + j.first);
            count -= 1;
        }
    }

    sort(vec.begin(), vec.end());
    int vec_size = vec.size();
    for (int i=0; i < vec_size; i++) {
        cout << vec[i];
    }

    cout << endl;
    return 0;
}