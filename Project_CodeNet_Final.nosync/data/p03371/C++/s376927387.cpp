#include <iostream>
#include <algorithm>
using namespace std;

int relu(int x){
    if(x >= 0){
        return x;
    }else{
        return 0;
    }
}

int main(){
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    int costs[3];
    costs[0] = X*A+Y*B;
    costs[1] = X*2*C+relu(Y-X)*B;
    costs[2] = relu(X-Y)*A+Y*2*C;
    sort(costs, costs+3);
    cout << costs[0];
    return EXIT_SUCCESS;
}