#include <iostream>
using namespace std;
int main(void){
    int N;
    int H[110];
    
    cin >> N;
    for(int i = 0; i < N; ++i) cin >> H[i];
    
    int wall = H[0];
    int count = 0;
    for(int i = 0; i < N; ++i){
        if(wall <= H[i]){
            wall = H[i];
            ++count;
        }
    }
    
    cout << count << endl;
}