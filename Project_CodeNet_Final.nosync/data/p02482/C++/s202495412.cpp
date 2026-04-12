#include <iostream>

int main ()
{
    using namespace std;
    int a, b;

    cin >> a >> b;
    cout << "a " << ( (a < b)? "<" : (a > b)? ">" : "==" ) << " b" << endl;
}