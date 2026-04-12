#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N;
    cin >> N;
    int H[N+1];
    H[0] = 0;
    for(int i = 1 ; i <= N ; i++){
        cin >> H[i];
    }
    
    int max = 0;
    int i = 1;
    int counter = 0;
    while(i <= N){
        if(max <= H[i] && H[i-1] <= H[i]) counter++;
        if(max < H[i]) max = H[i];
        i++;
    }
    cout << counter << endl;
    return 0;
}