#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<map>
using namespace std;
int main() {
    int N;
    cin >> N; 
    int y = N / 15;
    cout << N*800 - y*200 << endl;

    return 0;
}