#include <iostream>
#include <algorithm>

using namespace std;

int main(){
        int A,B,AB,X,Y;
        cin >> A >> B >> AB >> X >> Y;
        int AaB,ABaA,ABaB;

        if(X > Y) {
                swap(A,B);
                swap(X,Y);
        }
        // X < Y
        AaB = A*X + B*Y;
        ABaA = 2*AB*Y;
        ABaB = 2*AB*X + (Y-X)* B;

        cout << min(min(AaB,ABaA),ABaB) << endl;

        return 0;
}