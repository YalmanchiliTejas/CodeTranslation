#include <iostream>
using namespace std;

int main(){

    int X;
    int Y;
    int Z;
    int K;

    cin >> X;
    cin >> Y;
    cin >> Z;

    X = X - Z;
    K = Y + Z;

    cout << X / K << endl;
    return 0;


}