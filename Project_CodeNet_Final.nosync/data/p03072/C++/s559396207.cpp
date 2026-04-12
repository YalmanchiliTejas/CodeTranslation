#include <iostream>

using namespace std;

int main(void) {
    int N, max_height=0, result=0;
    cin >> N;
    
    int H[N];
    for (int i=0; i<N; i++) { cin >> H[i]; }

    for (auto x: H) { 
        if (x >= max_height) {
            result += 1;
            max_height = x;
        }
    }

    cout << result << flush;

}