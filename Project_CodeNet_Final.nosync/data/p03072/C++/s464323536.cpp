#include<bits/stdc++.h>
using namespace std;

int main(void){
    int N;
    cin >> N;
    vector <int> H(N);
    int ans = 0;
    for(int i = 0;i < N;i++){
        cin >> H[i];
        for(int j = 0;j <= i;j++){
            if(H[i] < H[j]){
                break;
            }
            if(i==j){
                ans++;
            }
        }
    }
    cout << ans << endl;
}