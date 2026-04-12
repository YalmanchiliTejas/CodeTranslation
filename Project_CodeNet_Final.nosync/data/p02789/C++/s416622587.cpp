#include <iostream>
using namespace std;
int main(){
    int numtest , passed;
    cin >> numtest >> passed;
    if (passed >= numtest) cout << "Yes";
    else cout << "No";
    return 0;
}