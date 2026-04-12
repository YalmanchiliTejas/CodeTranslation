#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    string s;
    cin >> n >> s;

    rep(v0, 2) {
        rep(v1, 2) {

            vector<int> v(n);  // v[i] : 0のとき'S',1のとき'W'

            v[0] = v0, v[1] = v1;
            for(int i = 1; i <= n-2; i++) {
        
                if(s[i] == 'o') {

                    if(v[i-1] == 0 && v[i] == 0) {
                        v[i+1] = 0;
                    }
                    else if(v[i-1] == 0 && v[i] == 1) {
                        v[i+1] = 1;
                    }
                    else if(v[i-1] == 1 && v[i] == 0) {
                        v[i+1] = 1;
                    }
                    else if(v[i-1] == 1 && v[i] == 1) {
                        v[i+1] = 0;
                    }

                }
                else {

                    if(v[i-1] == 0 && v[i] == 0) {
                        v[i+1] = 1;
                    }
                    else if(v[i-1] == 0 && v[i] == 1) {
                        v[i+1] = 0;
                    }
                    else if(v[i-1] == 1 && v[i] == 0) {
                        v[i+1] = 0;
                    }
                    else if(v[i-1] == 1 && v[i] == 1) {
                        v[i+1] = 1;
                    }

                }

            }

            vector<int> p(3), q(3);
            p[0] = v[n-1], p[1] = v[0], p[2] = v[1];
            q[0] = v[n-2], q[1] = v[n-1], q[2] = v[0];

            int flag = 0;
            if(s[0] == 'o') {
                if(p[1] == 0) {
                    if(p[0] != p[2]) {
                        flag = 1;
                    }
                }
                else if(p[0] == p[2]) {
                    flag = 1;
                }
            }
            else {
                if(p[1] == 0) {
                    if(p[0] == p[2]) {
                        flag = 1;
                    }
                }
                else if(p[0] != p[2]) {
                    flag = 1;
                }
            }

            if(s[n-1] == 'o') {
                if(q[1] == 0) {
                    if(q[0] != q[2]) {
                        flag = 1;
                    }
                }
                else if(q[0] == q[2]) {
                    flag = 1;
                }
            }
            else {
                if(q[1] == 0) {
                    if(q[0] == q[2]) {
                        flag = 1;
                    }
                }
                else if(q[0] != q[2]) {
                    flag = 1;
                }
            }

            if(!flag) {
                rep(i, n) {
                    if(v[i] == 0) {
                        cout << "S";
                    }
                    else {
                        cout << "W";
                    }
                }
                cout << endl;
                return 0;
            }

        }
    }

    cout << -1 << endl;
    return 0;
}