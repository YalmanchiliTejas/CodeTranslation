#include<iostream>
#include<vector>
using namespace std;

int main(){
    int N, height_max=0, count=0;
    vector<int> H;

    cin >> N;
    H.resize(N);
    for(int i=0; i<N; i++){
        cin >> H[i];
    }

    for(int i=0; i<N; i++){
        if(height_max <= H[i]){
            count++;
            height_max = H[i];
        }
    }

    cout << count << endl;

    return 0;
}