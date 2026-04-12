#include<iostream>
using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;
    string out = "==";
    if(x > y)
        out = ">";
    else if(x < y)
        out = "<";

    cout << "a " << out
            << " b\n";
}