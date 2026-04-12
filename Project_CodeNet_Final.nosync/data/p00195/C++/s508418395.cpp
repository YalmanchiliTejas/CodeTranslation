#include <bits/stdc++.h>
using namespace std;
int A[5][2];
int main(){
    while(cin >> A[0][0] >> A[0][1]){
        if(A[0][0] + A[0][1] == 0){
            return 0;
        }
        cin >> A[1][0] >> A[1][1] >> A[2][0] >> A[2][1] >> A[3][0] >> A[3][1] >> A[4][0] >> A[4][1];
        int a0 = A[0][0] + A[0][1], a1 = A[1][0] + A[1][1], a2 = A[2][0] + A[2][1], a3 = A[3][0] + A[3][1], a4 = A[4][0] + A[4][1];
        if(a0 >= a1 && a0 >= a2 && a0 >= a3 && a0 >= a4){
            cout << "A " << a0 << endl;
        }
        if(a1 >= a0 && a1 >= a2 && a1 >= a3 && a1 >= a4){
            cout << "B " << a1 << endl;
        }
        if(a2 >= a0 && a2 >= a1 && a2 >= a3 && a2 >= a4){
            cout << "C " << a2 << endl;
        }
        if(a3 >= a0 && a3 >= a1 && a3 >= a2 && a3 >= a4){
            cout << "D " << a3 << endl;
        }
        if(a4 >= a0 && a4 >= a1 && a4 >= a2 && a4 >= a3){
            cout << "E " << a4 << endl;
        }
    }
    //cout << 654231 << endl;
    return 0;
}