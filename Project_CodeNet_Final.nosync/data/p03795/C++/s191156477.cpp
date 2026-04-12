#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int N, x, y;

int main(){
    cin >> N;

    y = N / 15;

    cout << N*800 - y*200 << endl;
}
