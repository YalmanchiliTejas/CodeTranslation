#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> H(N);
    for(int i = 0; i < N; i++)
        cin >> H.at(i);

    bool t = true;
    int ans = 0;
    for(int i = 0;i < N; i++){
        for(int j = 0; j < i; j++){
            if(H[i] < H[j])
                t = false;
        }
        if(t) ans++;
        t = true;
    }
    
    cout << ans << endl;

    return 0;
}