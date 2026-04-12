#include<iostream>
using namespace std;

int main(){
    int N, max = 0, num = 0;
    cin >> N;
    int H[N];
    for(int i = 0; i < N; i++){
        cin >> H[i];
        if(max <= H[i]){
            max = H[i];
            num++;
        }
    }
    cout << num << endl;
    return 0;
}