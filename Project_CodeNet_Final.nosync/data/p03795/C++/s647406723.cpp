#include <bits/stdc++.h>
#include <algorithm>
#include<string>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, answer = 0;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        answer += 800;
        if (i % 15 == 0) {
            answer -= 200;
        }
    }
    cout << answer << endl;
    return 0;
}