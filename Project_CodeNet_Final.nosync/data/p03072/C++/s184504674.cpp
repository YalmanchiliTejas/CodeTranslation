#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int N; cin >> N;
    vector <int> H(N);
    for (int i = 0; i < N; i++){
        cin >> H.at(i);
    }
    int H_max = H.at(0);
    int ans = 0;
    for (int i = 0; i < N; i++){
        if (H.at(i) >= H_max){
            ans++;
            H_max = max(H_max,H.at(i));
        }
    }
    cout << ans << endl;
    
}
