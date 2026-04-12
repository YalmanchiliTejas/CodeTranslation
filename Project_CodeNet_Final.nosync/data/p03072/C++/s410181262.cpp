#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main(){
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i=0;i<N;i++){
        cin >> H[i];
    }
    int ma = 0;
    int ans = 0;
    for (int i=0;i<N;i++){
        if (i==0){
            ans += 1;
            ma = H[0];
        } else {
            if (ma <= H[i]){
                ans += 1;
                ma = H[i];
            }
        }
    }
    cout << ans << endl;
}