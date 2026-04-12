#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;


int main(int argc, char** argv){
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i=0; i<N; i++) cin >> H[i];

    int count = 1;
    for (int i=0; i<N; i++){
        if (i == 0) continue;
        bool flag = true;
        for (int j=0; j<i; j++){
            if (H[j] > H[i]){
                flag = false;
                break;
            }
        }
        if (flag == true) count++;
    }
    cout << count << endl;

    return 0;
}
