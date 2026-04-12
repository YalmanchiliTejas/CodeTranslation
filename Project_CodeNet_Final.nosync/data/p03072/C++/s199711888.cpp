#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    int N;
    cin >> N;
    int h[N];
    for(int i = 0; i < N; i++){
        cin >> h[i];
    }
    int count = 0;
    int m = 0;
    for(int i = 0; i < N; i++){
        if(m <= h[i]){
            count++;
        }
        m = max(m,h[i]);
    }
    cout << count << endl;

}