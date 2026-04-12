#include<iostream>
#include<string>
#include<map>
#define int long long int

using namespace std;

signed main(){

    int N, i, MaX = 0, count = 0;
    int H[200];


    cin >> N;
    for(i = 0; i < N; i++){
        cin >> H[i];

        if(H[i] >= MaX){
            MaX = H[i];
            count++;
        }
    }

    cout << count << endl;
    return 0;
}