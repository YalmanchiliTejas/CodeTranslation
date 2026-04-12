#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for(int i = 0; i < N; i++){
        cin >> H.at(i);
    }

    int sum = 1, heighest = H.at(0);
    for(int i = 1 ; i < N; i++){
        if(heighest <= H.at(i)){
            sum += 1; heighest = H.at(i);
        }
    }

    cout << sum << endl;
}
