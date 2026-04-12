#pragma region
#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, n) for (int i = n; i >= 0; i--)
#define repc(i, m, n) for (int i = m; i < n; i++)
#define reprc(i, m, n) for (int i = m; i > n; i--)
#define all(v) v.begin(), v.end
#define INF 1e9
#define EPS 1e-10
using namespace std;
typedef long long ll;
#pragma endregion

int main()
{
    int A,B,C,X,Y;
    ll m = 0;
    cin >> A >> B >> C >> X >> Y;

    C *= 2;

    if(A + B > C){
        m += C * min(X, Y);
        int c = max(X, Y) - min(X, Y);
        if(X > Y){
            if(A > C){
                m += C * c;
            }else{
                m += A * c;
            }
        }else{
            if(B > C){
                m += C * c;
            }else{
                m += B * c;
            }
        }
    }else{
        m += A * X + B * Y;
    }
    
    cout << m << endl;
}