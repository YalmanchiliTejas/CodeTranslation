#include <algorithm>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
int main(void){
    int x;
    cin >> x;
    if(x == 3 || x == 5 || x == 7){
        cout << "YES";
    } else{
        cout << "NO";
    }
    return 0;
}