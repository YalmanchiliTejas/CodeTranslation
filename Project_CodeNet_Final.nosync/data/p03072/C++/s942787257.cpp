#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;
    int H[25];
    int count = 1;
    int bfo;
    for(int i = 0; i < N; ++i){
        cin >> H[i];        
    }
    bool flag = true;
    for(int j = 1; j < N; j++){
        for(int k = 0; k < j; k++){
            if(H[k] > H[j]){
                flag = false;
            }
        }
        if(flag) count++;
        flag = true;
    }
    cout << count << endl;
}