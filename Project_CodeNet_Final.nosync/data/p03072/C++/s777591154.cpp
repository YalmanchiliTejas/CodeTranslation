#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> H(N);
    for(int i = 0; i < N; ++i) {
        cin >> H[i];
    }
    int ret = 1;
    int max = H[0];
    for(int i = 1; i < N; ++i) {
        if(max <= H[i]) {
            ret++;
            max = H[i];
        }
    }
    cout << ret << endl;
    return 0;
}