#include <bits/stdc++.h>
#define int long
#define ll long long
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
int gcd(int a,int b){return b ? gcd(b,a%b) : a;}
int lcm(int a,int b){return a/gcd(a,b)*b;}

main() {
    int A,B,C; cin >> A >> B >> C;
    int X,Y; cin >> X >> Y;
    int D,E,F;
    D=A*X+B*Y; 
    E=(X>Y ? Y*2*C+(X-Y)*A : (Y-X)*B+X*2*C);
    F=(X>Y ? X*2*C : Y*2*C);
    cout << min({D,E,F}) << endl;

    return 0;
}