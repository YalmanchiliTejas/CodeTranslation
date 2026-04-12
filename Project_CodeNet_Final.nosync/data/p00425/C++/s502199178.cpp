#include <iostream>
#include <string>
using namespace std;
int main() {
    int N;
    string op;
    cin >> N;
    while (N != 0) {
        int oneFace = 1;
        int twoFace = 2;
        int sum = 1;
        for (int i = 0; i < N; i++) {
            cin >> op;
            int transID;
            if (op == "North") transID = 0;
            if (op == "East") transID = 1;
            if (op == "West") transID = 2;
            if (op == "South") transID = 3;
            if (op == "Right") transID = 4;
            if (op == "Left") transID = 5;
            int trans[36] = {5,1,3,4,6,2,3,2,6,1,5,4,4,2,1,6,5,3,2,6,3,4,1,5,1,4,2,5,3,6,1,3,5,2,4,6};
            oneFace = trans[transID * 6 + oneFace - 1];
            twoFace = trans[transID * 6 + twoFace - 1];
            if (oneFace == 1) sum += 1;
            else if (twoFace == 1) sum += 2;
            else if (twoFace == 6) sum += 5;
            else if (oneFace == 6) sum += 6;
            else if (oneFace == 2 && twoFace == 3 ||
                oneFace == 3 && twoFace == 5 ||
                oneFace == 5 && twoFace == 4 ||
                oneFace == 4 && twoFace == 2) sum += 3;
            else sum += 4;
        }
        cout << sum << endl;
        cin >> N;
    }
}