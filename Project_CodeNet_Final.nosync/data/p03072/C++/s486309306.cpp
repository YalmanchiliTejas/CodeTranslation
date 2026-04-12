#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,max_height,count;
    cin >> N;
    max_height = 0;
    count = 0;
    vector<int> H(N);

    for (int i = 0; i < N; i++){
        cin >> H.at(i);
        if (H.at(i) >= max_height){
            count++;
            max_height = H.at(i);
        }
    }
    cout << count << endl;
    
}