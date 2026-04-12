#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    string messages = "No";
    if(N == M) {
        messages = "Yes";
    }
    cout << messages << endl;
    return 0;
}