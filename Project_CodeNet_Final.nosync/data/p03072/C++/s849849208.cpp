#include <iostream>
using namespace std;

int N;
int H[20] = {};
int main(){
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> H[i];
    }
    int maximum = 0;
    int num = 0;
    for (int i = 0; i < N; i++){
        if (maximum <= H[i]){
            maximum = H[i];
            num += 1;
        }
    }
    cout << num << endl;
    return 0;
}