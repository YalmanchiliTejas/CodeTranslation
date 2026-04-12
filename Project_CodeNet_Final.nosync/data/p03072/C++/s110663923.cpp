#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
//#define DEBUG
using namespace std;

int main(){
    int N;
    cin >> N;
    vector <int> H(N);
    for(int i = 0; i < N; i++){
        cin >> H.at(i);
    }
    int ans = 1;
    int max_h = H.at(0);
    for(int i = 1; i < N; i++){

        if(H.at(0) <= H.at(i) && H.at(i-1) <= H.at(i) && max_h <= H.at(i)){
            max_h = H.at(i);
            ans++;
        }
        
        
    }
    cout << ans << endl;
}