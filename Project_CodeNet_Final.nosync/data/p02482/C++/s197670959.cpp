#include <iostream>
using namespace std;

string compare(const int a, const int b)
{
    return a < b ? "<" : a > b ? ">" : "==";
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << "a "
         << compare(a, b)
         << " b" << endl;

    return 0;    
}