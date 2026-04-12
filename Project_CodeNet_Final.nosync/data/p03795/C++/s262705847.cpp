#include<iostream>
#include<string>
#include <cmath>
#include <ctype.h>
using namespace std;
int N;
int main() {
    cin >> N;
    cout << 800*N - 200*(N/15) << endl;
    return 0;
}