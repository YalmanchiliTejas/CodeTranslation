#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

int main(){
    int N; cin >> N;
    vector<int> X(N), Y(N);
    for(int i=0;i<N;i++){
        cin >> X[i];
        Y[i] = X[i];
    }
    sort(Y.begin(), Y.end());
    int Y1 = Y[N/2-1];
    int Y2 = Y[N/2];
    for(int i=0;i<N;i++){
        if(X[i] <= Y1) cout << Y2 << endl;
        else if(X[i] >= Y2) cout << Y1 << endl;
    }

    return 0;
}