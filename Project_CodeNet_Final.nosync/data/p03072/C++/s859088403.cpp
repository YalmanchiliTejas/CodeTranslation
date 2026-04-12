#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int N;
    int H[100] = {0};
    int result = 1;
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }
    
    for (int i = 1; i < N; i++) {
        int check = 0;
        for (int j = 0; j < i; j++) {
            if (H[j] > H[i]) {
                check = 1;
            }
        }
        if (check == 0) {
            result++;
        }
    }
    
    cout << result << endl;
    
    return 0;
}