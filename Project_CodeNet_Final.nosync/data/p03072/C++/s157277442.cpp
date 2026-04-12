#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void){
    int N;
    cin >> N;
    vector<int> H(N);
    if (N < 1 && N > 20)
        return 0;
    for(int i = 0;i < N;i++){
        cin >> H[i];
        if(H[i] < 1 && H[i] >100)
            return 0;
    }

    int max = 0;
    int count = 1;
    for(int i = 0; i < N; i++){
        if(i != 0){
            count = H[i] - H[i - 1] >= 0 && H[i] >= max ? count + 1 : count;
        }
        max = H[i] > max ?  H[i] : max;
    }
    cout << count << endl;
    return 0;
}
