#include <cstdio>
#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;

    int res = N / 15;

    cout << 800*N - 200*res << endl;

    return 0;
}
