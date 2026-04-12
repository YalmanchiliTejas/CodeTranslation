#include <iostream>
using namespace std;
int main(){
    int N;
    cin >> N;
    cout << N * 800 - (N - N % 15) / 15 * 200 << endl;
    return 0;
}