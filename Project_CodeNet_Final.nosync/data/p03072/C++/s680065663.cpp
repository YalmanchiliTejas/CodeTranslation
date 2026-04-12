#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    int N; cin >> N;
    vector<int> H(N); for(int i=0; i<N; i++) cin >> H[i];
    int max=0;
    int cnt=0;
    for(int i=0; i<N; i++){
        if(max<=H[i]){
            cnt++;
            max = H[i];
        }
    }
    cout << cnt << endl;
}