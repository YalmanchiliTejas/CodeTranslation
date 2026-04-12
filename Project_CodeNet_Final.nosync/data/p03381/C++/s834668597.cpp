#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;

int main(){

    int N;
    cin >> N;
    vector<int> X(N);
    for(int i = 0; i < N; i++){
        cin >> X[i];
    }

    vector<int> A = X;

    sort(A.begin(), A.end());

    int med = A[(N + 1) / 2 - 1];
    for(int i = 0; i < N; i++){
        int temp = X[i];
        if(N % 2 == 0){
            if(temp <= med){
                cout << A[(N + 1) / 2] << "\n";
            }  
            else{
                cout << med << "\n";
            }
        }
        else{
            if(temp < med){
                cout << med << "\n";
            }
            else{
                cout << A[(N + 1) / 2] << "\n";
            }
        }
    }

    return 0;
}