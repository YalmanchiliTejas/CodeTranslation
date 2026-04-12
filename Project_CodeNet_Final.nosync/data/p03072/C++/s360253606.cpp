#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> H(N);
    for(int i = 0; i < N; i++){
        cin >> H.at(i);
    }

    int count = 0;
    
    for(int i = 1; i < N; i++){
        bool flg = true;

        for(int j = 0; j < i; j++){
            if(H.at(i) < H.at(j)){
                flg = false;
            }
        }

        if(flg) count++;
    }
    cout << count+1 << endl;
}