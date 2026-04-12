#include <bits/stdc++.h>

using namespace std;

int n, x;
deque <int> dq;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> x;
        if (i & 1)
            dq.push_front(x);
        else
            dq.push_back(x);
    }
    if (n & 1)
        for (auto u: dq)
            cout << u << ' ';
    else
        while (dq.size()){
            cout << dq.back() << ' ';
            dq.pop_back();
        }
}
