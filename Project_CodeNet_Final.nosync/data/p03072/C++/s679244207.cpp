#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    int N;
    cin >> N;
    
    vector<int> mountains(N);
    for (int i = 0; i < N; i++) cin >> mountains[i];
    
    int tallest_mountain = mountains[0];
    int total = 1;
    for (int i = 1; i < N; i++){
        if (mountains[i] >= tallest_mountain) {
            total++;
            tallest_mountain = mountains[i];
        }
    }
    
    cout << total << endl;
}