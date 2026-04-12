#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <bitset>
#include <tuple>
#include <stack>
#include <utility>

using namespace std;
typedef long long ll;

int main(){
    int N;
    cin >> N;
    vector<int> H(N);
    for(int i=0; i<N; i++) cin >> H[i];

    int Hmax=H[0], ans=1;
    for(int i=1; i<N; i++){
        if(H[i] >= Hmax){
            ans += 1;
            Hmax = H[i];
        }
    }
    cout << ans << endl;
    return 0;
}