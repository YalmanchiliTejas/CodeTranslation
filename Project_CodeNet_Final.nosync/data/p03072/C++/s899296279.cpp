#include <iostream>
using namespace std;

int main(){
    int N;
    int H_list[100];
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> H_list[i];   
    }
    long long cnt = 0;
    for(int i=0;i<N;i++){
        bool flg = true;
        for(int j=0;j<=i-1;j++){
            if(H_list[j] > H_list[i]){
                flg = false;
                break;
            }
        }
        if(flg){
            cnt++;
        }
    }
    cout << cnt;
    return EXIT_SUCCESS;
}