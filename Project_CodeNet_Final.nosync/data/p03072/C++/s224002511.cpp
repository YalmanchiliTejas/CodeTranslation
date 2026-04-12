#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;



int main(){
    //input
    /*
    int A = 5;
    int B = 4;
    */
    int N ;
    cin >> N;
    vector<int> H(N,0);
    for (int i = 0; i < N; i++){
        cin >> H[i];
    }
    int tmp = H[0];
    int ans = 0;
    for (int i = 0; i < N; i++){
        if (H[i] >= tmp){
            tmp = H[i];
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}