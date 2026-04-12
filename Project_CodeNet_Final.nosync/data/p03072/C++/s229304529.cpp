#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main(){
    int N;
    int H[21] = {};
    int ans = 0, max = 0;
    cin >> N;
    for(int i=1; i<=N;i++){
        cin >> H[i];
        if(max <= H[i]){
            ans++;
            max = H[i];
        }
    }
    cout << ans << endl;
}
