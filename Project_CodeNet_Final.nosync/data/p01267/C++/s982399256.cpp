#include <iostream>
using namespace std;

int main(void){
    
    
    while(1) {
        int N, A, B, C, X;
        int Y[100];
        cin >> N >> A >> B >> C >> X;
        if (N==0) break;
        for(int i=0; i<N; i++) cin >> Y[i];
        int y_index=0;
        for(int i=0; i<=10000; i++) {
            if (Y[y_index] == X) {
                y_index++;
                if (y_index == N) {
                    cout << i << endl;
                    break;
                }
            }
            X = (A * X + B) % C;
        }
        if (y_index != N) {
            cout << -1 << endl;
        }
    }
    
}