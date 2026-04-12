#include<iostream>
using namespace std;

int main() {
    int N;
    int A[30];
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];

    int c = 1;
    bool higher = true;
    for (int i = 1; i < N; i++) {
        higher = true;
        for(int j = 0; j < i; j++) {
            higher *= (A[j] <= A[i]);
        }
        if (higher) c++;
    }

    cout << c << endl;
    return 0;
}