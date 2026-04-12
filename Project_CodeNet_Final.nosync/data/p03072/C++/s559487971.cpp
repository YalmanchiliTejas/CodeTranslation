#include <iostream>
using namespace std;

int main(void) {
    int N;cin>>N;
    int now = 0;
    int result = 0;
    for (int i = 0; i < N; i++) {
        int H;cin>>H;
        if (now <= H) {
            result++;
            now = H;
        }
    }
    cout << result << endl;
    return 0;
}