#include <iostream>
using namespace std;

int main() {
    int N;
    int M = 0, ans = 0;
    
    cin >> N;
    for (int i = 0; i < N; ++i){
        int t;
        cin >> t;
        if (t >= M){
            M = t;
            ans++;
        }
    }   
    cout << ans << endl;
}