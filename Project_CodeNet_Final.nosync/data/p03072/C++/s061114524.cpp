#include<iostream>
using namespace std;

int main(){
    int N;
    cin >> N;

    int H[N];

    for(int i = 0; i < N; i++){
        cin >> H[i];
    }

    int cou = 1;
    int max = H[0];

    for(int i = 1; i < N; i++){
        if(max <= H[i]){
            cou++;
            max = H[i];
        }
    }

    cout << cou << endl;
}