#include <iostream>

using namespace std;

int main(){

    int N;
    cin >> N;
    int H[N];
    int border;
    int count = 1;

    for(int i = 0; i < N; i++){
        cin >> H[i];
        if(i == 0){
            border = H[i];
        }else if(H[i] >= border){
            border = H[i];
            count++;
        }
    }
    cout << count << endl;

    return 0;
}