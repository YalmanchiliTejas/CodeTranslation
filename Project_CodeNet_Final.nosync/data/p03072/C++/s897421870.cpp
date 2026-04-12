#include <iostream>
using namespace std;

int main()
{
    int N; cin >> N;
    int H[N];
    for(int i = 0; i < N; ++i) {
        cin >> H[i];
    }
    int max = 0;
    int cnt = 0;
    for(int i = 0; i < N; ++i) {
        if(H[i] >= max) {
            max = H[i];
            cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}
