#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    vector<int> X;
    vector<int> sortedX;

    cin >> N;
    for(int i=0; i<N; i++) {
        int x;
        cin >> x;
        X.push_back(x);
        sortedX.push_back(x);
    }

    sort(sortedX.begin(), sortedX.end());
    
    auto itr = sortedX.end();
    for(int i=0; i < N/2; i++) {
        itr--;
    }

    for(int i=0; i<N; i++) {
        if(X[i] < *itr) {
            cout << *itr << endl;
        } else {
            cout << *(itr-1) << endl;
        }
    }
}