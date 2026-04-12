#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){

    int r, g, b;
    int sum;
    cin >> r >> g >> b;
    sum = r*100 + g*10 + b;

    if(sum % 4 == 0){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}
