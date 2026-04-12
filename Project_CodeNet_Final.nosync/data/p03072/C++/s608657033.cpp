#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(int argc, char const *argv[]) {
    int N;
    int H [30];
    cin >> N;
    for (int i = 0; i < N; i++ ){
        cin >> H[i];
    }
    int count=0;
    int max = 0;
    for (int i = 0; i<N;i++){
        if (max <= H[i]){
                max = H[i];
                count++;
            }
      }
    cout << count << endl;
}