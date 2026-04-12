#include<iostream>
using namespace std;

int main(){
    int N;
    cin >> N;

    int k = 0;

    if(N < 15){
        cout << 800 * N << endl;
    }else{
        k = N / 15;

        cout << 800 * N - 200 * k << endl;
    }
}