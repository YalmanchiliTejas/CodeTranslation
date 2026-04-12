#include <iostream>
#include <utility>

using namespace std;

int main(){
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    if (X < Y){
        swap(A, B);
        swap(X, Y);
    }

    int min_cost = 2e9;
    for (int a = 0; a <= X; a++){
        int ab = X - a;

        int b;
        if (Y - ab > 0) b = Y - ab;
        else b = 0;

        int cost = A*a + B*b + 2*C*ab;
        if (cost < min_cost) min_cost = cost;
    }

    cout << min_cost << endl;
    return 0;
}