#include <iostream>

using namespace std;

int main()
{
    int r, g, b;
    cin >> r >> g >> b;
    r *= 100;
    g *= 10;
    b *= 1;
    int sum;
    sum = r + g + b;
    if(sum % 4 == 0){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}
