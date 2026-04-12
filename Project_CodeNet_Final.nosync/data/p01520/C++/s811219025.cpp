#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int N, T, E;
    vector<int> x;

    cin >> N >> T >> E;
    for(int i=0; i < N; i++){
        int input;
        cin >> input;
        x.push_back(input);
    }
    bool isPossible = false;
    for(int i=E*(-1); i <= E && !isPossible; i++){
        for(int j=0; j < N && !isPossible; j++){
            if((i+T)%x[j] == 0){
                cout << j+1 << endl;
                isPossible = true;
            }
        }
    }
    if(!isPossible) cout << -1 << endl;
}