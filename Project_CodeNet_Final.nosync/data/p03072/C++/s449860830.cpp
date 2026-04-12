#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, H[21], tmp, cnt;
    cin >> N;
    tmp = 0;
    cnt = 0;
    for(int i = 0; i < N; i++){
        cin >> H[i];
        if(tmp <= H[i]){
            cnt++;
            tmp = H[i];
        }
    }
    cout << cnt << endl;
    return 0;
}