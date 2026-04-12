#include <iostream>
using namespace std;

int main(){
    int N;
    int H[1000];

    cin >> N;
    for (int i = 0; i < N; ++i ) cin >> H[i];
    
    int max_h = H[0];
    int c = 1;

    for (int i = 1; i < N; ++i) {
        if (max_h <= H[i]) {
            ++c;
            max_h = H[i];
        }
    
    }
    cout << c << endl;

    return 0;
}
