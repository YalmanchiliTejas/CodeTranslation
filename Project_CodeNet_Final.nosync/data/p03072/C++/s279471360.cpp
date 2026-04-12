#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    int H[100];
    for(int i = 0; i < N; i++){
       cin >> H[i]; 
    }
    int count = 0;
    int max = 0;
    for(int i = 0; i < N; i++){
        if(H[i] > max){
            max = H[i];
        }
        if(max <= H[i]){
            count++;
        }
    }
    cout << count << endl;
}