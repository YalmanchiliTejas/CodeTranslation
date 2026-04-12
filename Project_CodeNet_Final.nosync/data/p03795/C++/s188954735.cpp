#include <iostream>

using namespace std;

int main(void){
    int n=0;
    int x=0;
    int y=0;

    cin >> n;

    x=n*800;
    y=(n/15)*200;

    cout << x-y << endl;

    return 0;
}