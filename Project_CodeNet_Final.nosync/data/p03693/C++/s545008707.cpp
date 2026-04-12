#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <iomanip>


using namespace std;

int main() {
    
    int r,g,b;
    cin >> r >> g >> b;
    int jud;
    jud = 100 * r + 10*g + b;
    if (jud % 4 == 0){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }


}
