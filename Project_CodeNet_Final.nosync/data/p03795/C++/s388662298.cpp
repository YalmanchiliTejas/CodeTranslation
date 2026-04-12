#include <cstdio>                                         
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int N; cin >> N;

    cout << 800*N - 200*(floor(N/15)) << endl;
    return 0;
}