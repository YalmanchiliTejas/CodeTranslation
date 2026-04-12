#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void){
    int N;
    long long X[200000];
    long long Y[200000];
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> X[i];
        Y[i]=X[i];
    }
    sort(X,X+N);
    for (int i = 0; i < N; i++) {
        if(Y[i]>X[(N/2)-1]){
            cout << X[(N/2)-1] << endl;   
        }else{
            cout << X[(N/2)] << endl;   
        }
    }
}
