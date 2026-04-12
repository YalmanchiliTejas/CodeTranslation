#include<iostream>
#include<string>

using namespace std;
int main ()
{
    string station;
    cin >> station;
    if(station=="AAA" || station=="BBB") {
        cout << "No" << endl;
    }
    else {
        cout << "Yes" << endl;
    }
}

