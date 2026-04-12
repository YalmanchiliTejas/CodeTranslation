/**
 * C - Half and Half
 * https://atcoder.jp/contests/abc095/tasks/arc096_a
 * 
 * pa + pb < pc *2
この時、min(x,y) は、A,B で買う

pa + pb > pc *2
の時、min(x,y) は、Cで買う

その後、abs(x-y)を買う
x<y & py<2pc
Bを abs(x-y)pb
x<y & py>2pc
Cを　2abs(x-y)pc
x>y & pa<2pc
Aを　abs(x-y)pa
x>y & pa>2pc
Pを 2abs(x-y)pc
 **/
#include<iostream>

using namespace std;

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    int ans = 0;
    if(A+B>=2*C) {
        ans += min(X, Y)*2*C;
    } else {
        ans += min(X, Y)*(A+B);
    }

    if(X>Y&A<2*C) {
        ans += abs(X-Y)*A;
    } else if(X>Y&A>2*C) {
        ans += abs(X-Y)*2*C;
    } else if(X<Y&B<2*C) {
        ans += abs(X-Y)*B;
    } else if(X<Y&B>2*C) {
        ans += abs(X-Y)*2*C;
    }

    cout << ans << endl;
}