#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

int N;
string S;

int main() {
    cin >> N;
    bool even = N % 2;
    stack<int> s;
    queue<int> q;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if (even ^ i % 2) {
            s.push(a);
        } else {
            q.push(a);
        }
    }
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}