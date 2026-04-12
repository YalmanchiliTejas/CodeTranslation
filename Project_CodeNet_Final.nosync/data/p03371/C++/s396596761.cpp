#include <iostream>
#include <string>
using namespace std;
using ll=long long;

int main(){
    int A, B, C;
    ll X, Y;
    cin >> A >> B >> C >> X >> Y;
    ll easy = A * X + B * Y;
    ll maxnum = max(X, Y) * 2;
    for(ll i = maxnum; i > 1; i -= 2){
        ll tmp;
        if (i == maxnum) tmp = C * i;
        else if (X - (i / 2) > 0 && Y - (i / 2) > 0) tmp = A * (X - (i / 2)) + B * (Y - (i / 2)) + C * i;
        else if (X - (i / 2) > 0) tmp = A * (X - (i / 2)) + C * i;
        else if (Y - (i / 2) > 0) tmp = B * (Y - (i / 2)) + C * i;
        if (tmp < easy) easy = tmp;
    }
    cout << easy << endl;
    return 0;
}