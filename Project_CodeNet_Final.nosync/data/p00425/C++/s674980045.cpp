#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
    int N;
    while(cin >> N && N!=0) {
        int A=1, B=2, C=3;
        vector<string> order(N);
        for(int i=0; i<N; ++i) {
            cin >> order[i];
        }

        int ret=1;
        for(int i=0; i<N; ++i) {
            if(order[i] == "North") {
                swap(A, B);
                B = 7 - B;
            } else if(order[i] == "East") {
                swap(A, C);
                A = 7 - A;
            } else if(order[i] == "West") {
                swap(A, C);
                C = 7 - C;
            } else if(order[i] == "South") {
                swap(A, B);
                A = 7 - A;
            } else if(order[i] == "Right") {
                swap(B, C);
                C = 7 - C;
            } else if(order[i] == "Left") {
                swap(B, C);
                B = 7 - B;
            }
            ret += A;
        }
        cout << ret << endl;
    }
}