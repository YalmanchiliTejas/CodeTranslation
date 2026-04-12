#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
   
    int cost1, cost2, cost3, cost4;
    // AピザX枚，BピザY枚
    cost1 = A*X + B*Y;

    // AのためにABを使って残りはBを買う
    cost2 = 2*C*X + B*max(0, Y-X);

    // BのためにABを使って残りはAを買う
    cost3 = A*max(0, X-Y) + 2*C*Y; 

    // すべてABで補う
    cost4 = 2*C*max(X, Y);

    cout << min({cost1, cost2, cost3, cost4}) << endl;

}
