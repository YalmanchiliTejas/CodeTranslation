#include<iostream>
using namespace std;
int main(){
    int N;
    cin >> N;
    int H[N];
    for(int i  = 0; i < N; ++i) cin >> H[i];
    int max = 0;
    int count;
    for(int i = 0; i < N; ++i){
        if(i == 0){
            count = 1;
            max = H[i];
        }
        else{
            if(H[i] >= max){
                max = H[i];
                count++;
            }
        }
    }
    cout << count << endl;
}