#include <iostream>

using namespace std;

int main(void)
{
    int r, g, b, x;

    cin >> r >> g >> b;

    x = r*100+g*10+b;

    if(x%4==0){
        cout << "YES" << endl;
    }

    else{
        cout << "NO" << endl;
    }

    return 0;
}