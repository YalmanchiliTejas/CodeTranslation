#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int inf = (1 << 30);
int mod = 1e9;
long long long_inf = (1LL << 60);

int main(){

    int N;
    cin >> N;
    vector<int> H(N);
    for(int i = 0; i < N; i++) cin >> H[i];

    int ans = 0, top = 0;
    for(int i = 0; i < N; i++){
        if(top <= H[i]){
            top = H[i];
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}