#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    int H[N];
    for(int i = 0;i < N;i++){
        cin >> H[i];
    }

    int count = 1;
    int m = H[0];

    for(int i = 1;i < N;i++){
        if(H[i] >= m){
            count++;
            m = H[i];
        }
        
    }
    cout << count << endl;
}