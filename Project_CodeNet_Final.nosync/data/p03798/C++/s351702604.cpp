#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define pb push_back
int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)

ll n;
char s[200000];
bool a[200000];

int main(){
    cin >> n;
    cin >> s;

    REP(ani1,2) {
        REP(ani2,2) {
            a[0] = ani1;
            a[1] = ani2;


            FOR(i,2,n) {
                if(a[i - 1] ^ (s[i - 1] == 'o')) {
                    a[i] = !a[i - 2];
                }else {
                    a[i] = a[i - 2];
                }
            }

            bool f = true;

            if(a[0]) {
                if(s[0] == 'o') {
                    if(a[n - 1] != a[1]) {
                        f = false;
                    }
                }else {
                    if(a[n - 1] == a[1]) {
                        f = false;
                    }
                }
            }else {
                if(s[0] == 'o') {
                    if(a[n - 1] == a[1]) {
                        f = false;
                    }
                }else {
                    if(a[n - 1] != a[1]) {
                        f = false;
                    }
                }
            }
            if(a[n - 1]) {
                if(s[n - 1] == 'o') {
                    if(a[n - 2] != a[0]) {
                        f = false;
                    }
                }else {
                    if(a[n - 2] == a[0]) {
                        f = false;
                    }
                }
            }else {
                if(s[n - 1] == 'o') {
                    if(a[n - 2] == a[0]) {
                        f = false;
                    }
                }else {
                    if(a[n - 2] != a[0]) {
                        f = false;
                    }
                }
            }
            if(f) {
                REP(i,n) {
                    if(a[i]) {
                        cout << 'S';
                    }else {
                        cout << 'W';
                    }
                }
                cout << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
}