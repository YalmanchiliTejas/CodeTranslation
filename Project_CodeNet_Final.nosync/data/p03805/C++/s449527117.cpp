#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <bitset>
#include <iomanip>

using namespace std;

bool existEdge(const vector<int>& a, const vector<int>& b, int s, int e) {
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] == s && b[i] == e) {
            return true;
        }
    }
    return false;
}

int main() {
    int M, N;
    cin >> N >> M;
    vector<int> a;
    vector<int> b;
    for (int i = 0; i < M; ++i) {
        int tempa, tempb;
        cin >> tempa >> tempb;
        a.push_back(tempa);
        b.push_back(tempb);
        a.push_back(tempb);
        b.push_back(tempa);
    }

    vector<int> vertex(N, 0);
    for (int i = 0; i < N; ++i) {
        vertex[i] = i + 1;
    }

    int counter = 0;
    do {
        bool exist = true;
        for (int i = 1; i < N; ++i) {
            if (existEdge(a, b, vertex[i - 1], vertex[i])) {
                continue;
            }
            else {
                exist = false;
                break;
            }
        }
        if (exist) {
            ++counter;
        }
    } while (next_permutation(vertex.begin() + 1, vertex.end()));

    cout << counter << endl;
    //cout << setprecision(15) << endl;
    return 0;
}
