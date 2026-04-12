#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef long double ld;


char rev(char x) {
    if(x == 'S') return 'W';
    else return 'S';
}

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    string s;
    cin >> s;

    vector<string> a(4);

    a[0] = "SS";
    a[1] = "SW";
    a[2] = "WS";
    a[3] = "WW";

    for(int i = 0; i < 4; i++) {
        for(int j = 1; j < N - 1; j++) {
            if(a[i][j] == 'S') {
                if(s[j] == 'o') {
                    a[i].push_back(a[i][j - 1]);
                } else {
                    a[i].push_back(rev(a[i][j - 1]));
                }
            } else {
                if(s[j] == 'o') {
                    a[i].push_back(rev(a[i][j - 1]));
                } else {
                    a[i].push_back(a[i][j - 1]);
                }
            }
        }

        if(a[i][0] == 'S') {
            if(s[0] == 'o') {
                if(a[i][1] != a[i][N - 1]) continue;
            } else {
                if(a[i][1] == a[i][N - 1]) continue;
            }
        } else {
            if(s[0] == 'o') {
                if(a[i][1] == a[i][N - 1]) continue;
            } else {
                if(a[i][1] != a[i][N - 1]) continue;
            }
        }

        if(a[i][N - 1] == 'S') {
            if(s[N - 1] == 'o') {
                if(a[i][0] != a[i][N - 2]) continue;
            } else {
                if(a[i][0] == a[i][N - 2]) continue;
            }
        } else {
            if(s[N - 1] == 'o') {
                if(a[i][0] == a[i][N - 2]) continue;
            } else {
                if(a[i][0] != a[i][N - 2]) continue;
            }
        }

        cout << a[i] << endl;
        return 0;
    }

    cout << -1 << endl;
}