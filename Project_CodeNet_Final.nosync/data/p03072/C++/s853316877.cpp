#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#define INF 10000000;
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> H(n);
    int ans=1;
    int tmp_max = INF;
    for (int i=0;i<n;i++) cin >> H[i];
    tmp_max= H[0];
    for (int i=1;i<n;i++){
        if (tmp_max<=H[i]){
            ans += 1;
            tmp_max = H[i];
        }
    }
    cout << ans << endl;
}