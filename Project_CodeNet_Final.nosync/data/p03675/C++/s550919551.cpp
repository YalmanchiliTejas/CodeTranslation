#include<bits/stdc++.h>
#define rep(i,a,n) for (int i = a;i < n;i++)
using namespace std;

int main() {
    int a;
    deque<int> some;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (i % 2 == n % 2) {
            some.push_back(a);
        } else {
            some.push_front(a);
        }
    }
    for (int x:some) {
        cout << x << endl;
    }
}