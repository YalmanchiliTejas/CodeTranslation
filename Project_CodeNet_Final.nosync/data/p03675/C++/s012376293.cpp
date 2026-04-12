#include <iostream>
#include <vector>
using namespace std;
int main(void){
    // Here your code !
    int N, buf;
    cin >> N;
    vector<int> b = vector<int>(N);
    for(int i=0; i<N; i++){
        cin >> buf;
        if(i%2 == 0){
            b[N/2 + i/2] = buf;
        }else{
            b[N/2 - i/2 - 1] = buf;
        }
    }
    if(N%2 == 1){
        for(int i =N-1; i>=0; i--){
            cout << b[i] << " "; 
        }
    }else{
        for(int i=0; i<N; i++){
            cout << b[i] << " ";
        }
    }
    cout << endl;
    return 0;
}
