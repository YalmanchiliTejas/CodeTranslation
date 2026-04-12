#include <bits/stdc++.h>
using namespace std;

char solve(string& expr, int ans) {
    for (int i = 0; i < int(expr.size()); i += 2) expr[i] -= '0';
    return "ILMU"[
        ([&] {
            int ans_ = expr[0];
            for (int i = 1; i < int(expr.size()); i += 2) {
                ans_ = expr[i] == '+' ? ans_ + expr[i + 1]: ans_ * expr[i + 1];
            }
            return ans == ans_;
        }() << 0) |
        ([&] {
            stack<int> s; s.push(expr[0]);
            for (int i = 1; i < int(expr.size()); i += 2) {
                if (expr[i] == '+') s.push(expr[i + 1]);
                else {
                    int e = s.top() * expr[i + 1];
                    s.pop(); s.push(e);
                }
            }
            int ans_ = 0;
            for (; !s.empty(); s.pop()) ans_ += s.top();
            return ans == ans_;
        }() << 1)];
}

int main() {
    string expr; int ans;
    cin >> expr >> ans;
    cout << solve(expr, ans) << endl;
}