#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> H(N);
    for(int i=0; i<N; i++)
        cin >> H[i];
    int ans = 0;
    for(int i=0; i<N; i++){
        bool ok = true;
        for(int j=0; j<i; j++){
            if(H[j] > H[i]){
                ok = false;
                break;
            }
        }
        if(ok)
            ans++;
    }
    cout << ans << endl;
    return 0;
}