#include <iostream>

using namespace std;

int main(){
    int N, num = 1, maxh;
    cin >> N;
    int H[N];
    for(int i = 0; i < N; i++) cin >> H[i];
    maxh = H[0];
    for(int i = 1; i < N; i++){
        if(H[i] >= maxh){
            num++;
            maxh = H[i];
        }
    }
    cout << num << endl;
}