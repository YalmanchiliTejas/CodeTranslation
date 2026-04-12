#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<long long int> X(N), sortedX(N);
    for(int n=0; n<N; n++) {
        cin >> X[n];
    }
    
    sortedX = X;
    sort(sortedX.begin(), sortedX.end());
    for(int n=0; n<N; n++) {
        if(X[n]<=sortedX[N/2-1]) {
            cout << sortedX[N/2] << endl;
        } else {
            cout << sortedX[N/2-1] << endl;
        }
    }


    return 0;
    
}