#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main(){
    int N;
    cin >> N;
    int H[N];
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    int counter = 0;
    for(int i = 0; i < N; ++i){
        bool canSee = true;
        for(int j = 0; j < i+1; j++){
            if(H[j] > H[i]){
                canSee = false;
            }
        }
        if (canSee){
            counter++;
        }
    }

    cout << counter << endl;

    return 0;
}