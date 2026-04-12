#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> X(N);
    for(int i=0; i<N; i++) cin >> X[i];
    vector<int> Y = X;
    sort(Y.begin(), Y.end());

    int a = Y[N/2-1];
    int b = Y[N/2];

    for(int i=0; i<N; i++){
        if(X[i] < b) cout << b << endl;
        else cout << a << endl;
    }


    return 0;
}