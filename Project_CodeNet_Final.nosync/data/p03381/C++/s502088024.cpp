#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <functional>
#include <array>

using namespace std;

int64_t X[200001];
int64_t X2[200001];
int main(){
    int N;
    cin >> N;

    for(int i = 0; i < N; ++i){
        cin >> X[i];
        X2[i] = X[i];
    }
    sort(X, X + N);
    long double med = (X[N / 2 - 1] + X[N / 2]) / 2.0;
    for(int i = 0; i < N; ++i){
        if(med <= X2[i]){
            cout << X[N / 2 - 1] << endl;
        } else {
            cout << X[N / 2] << endl;
        }
    }
}