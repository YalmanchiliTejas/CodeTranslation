#include <iostream>
using namespace std;

int N, K;
int main(void){
    // Your code here!
    cin >> N;
    char S[N];
    cin >> S;
    cin >> K;
    
    char tmp = S[K-1];
    
    for(int i = 0; i < N; i++){
        if(tmp==S[i]){
            cout << S[i];
        } else{
            cout << "*";
        }
    }
    
    cout << endl;
}
