
#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 1e9


int main() {
    int A,B,C,X,Y;
    cin >>A>>B>>C>>X>>Y;
    if (A+B<=2*C){
        cout << A*X + B*Y << endl;
    }
    else{
        if(X>Y){
            if (A<2*C){
                cout << 2*C*Y + A*(X-Y) << endl;
            }
            else{
                cout << 2*C*X << endl;
            }
        }
        else if(X<Y){
            if (B<2*C){
                cout << 2*C*X + B*(Y-X) << endl;
            }
            else{
                cout << 2*C*Y << endl;
            }

        }
        else if(X==Y){
            cout << 2*C*X << endl;
        }
    }
    return 0;
}
