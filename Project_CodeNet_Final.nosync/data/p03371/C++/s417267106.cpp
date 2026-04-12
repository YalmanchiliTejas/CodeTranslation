#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    int cost = 0;
    if(A + B <= 2*C){
        cost = A * X + B * Y;
    }else{
        if(X < Y){
            cost = X * 2 * C;
            cost += (Y - X) * min(2 * C, B);
        }else if(X == Y){
            cost = X * 2 * C;
        }else{
            cost = Y * 2 * C;
            cost += (X - Y) * min(2 * C, A);
        }

    }
    cout << cost << endl;
    return 0;
}