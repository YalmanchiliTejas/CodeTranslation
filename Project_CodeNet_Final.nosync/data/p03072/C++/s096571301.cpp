#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> H(N);
    for(int i  =0 ; i < N; i++) cin >> H[i];
    int m = 0;
    int cnt = 1;
    for(int i = 0; i < N; i++){
        if(i == 0) m = max(m, H[i]);
        else{
            if(H[i] >= m) cnt++;
            m = max(H[i], m);
        }
    }
    cout << cnt << endl;
}