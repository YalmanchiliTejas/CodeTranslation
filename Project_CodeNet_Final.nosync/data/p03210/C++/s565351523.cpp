#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);

    int k;

    cin>> k;

    cout << ((k == 3 or k == 5 or k == 7) ? "YES" : "NO") << endl;
}