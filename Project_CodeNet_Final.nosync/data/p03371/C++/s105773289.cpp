#include <bits/stdc++.h>
using namespace std;
typedef priority_queue <int> pi;
typedef priority_queue <int, vector<int>, greater<int>> pg;
typedef unsigned long long int ulli;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    long long int X, Y;
    cin >> X >> Y;
    long long int ans = 0;
    while(X != 0 || Y != 0) {
        if(X != 0 && Y!= 0) {
            if(A + B < C * 2) {
                ans += (A + B);
                --X;
                --Y;
            } else {
                ans += C * 2;
                --X;
                --Y;
            }
        }else if(X != 0 && Y == 0) {
            if(A < C * 2) {
                ans += A;
                --X;
            } else {
                ans += C * 2;
                --X;
            }
        } else if(X == 0 && Y != 0) {
            if(B < C * 2) {
                ans += B;
                --Y;
            } else {
                ans += C * 2;
                --Y;
            }
        }
    }

    cout << ans << endl;
}