#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    int n, all;
    cin >> n;
    all = n * 800;
    n = n / 15;

    cout << all - n * 200 << endl;
    
    return 0;
}