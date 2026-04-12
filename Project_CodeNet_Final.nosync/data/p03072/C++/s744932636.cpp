#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int N;
    int H[30];
    int counter = 1;
    cin >> N;
    for(int i = 0; i < N; i++) cin >> H[i];

    int min = H[0];
    for(int i = 1; i < N; i++) {
        if(min <= H[i]) {
            min = H[i];
            counter++;
        }
    }
    cout << counter << endl;


    return 0;
}