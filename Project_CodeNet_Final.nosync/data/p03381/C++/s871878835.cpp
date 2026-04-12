#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int N;
    vector<int> X, tempX;
    cin >> N;
    
    int temp;
    
    for(int i = 0; i < N; i++){
        cin >> temp;
        X.push_back(temp);
        tempX.push_back(temp);
    }
    
    sort(tempX.rbegin(), tempX.rend());
    int l = N - 1;
    for(int i = 0; i < N; i++){
        if(X[i]  > tempX[N/2])
            cout << tempX[l/2 + 1] << endl;
        else
            cout << tempX[l/2] << endl;
    }
}
