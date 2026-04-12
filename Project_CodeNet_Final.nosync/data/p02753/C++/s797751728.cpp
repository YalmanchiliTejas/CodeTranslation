#include <iostream>

using namespace std;

int main()
{
    string S, A;

    cin >> S;

    A = "Yes";

    if (S == "AAA")
    {

        A = "No";
    }

    if (S == "BBB")
    {

        A = "No";
    }

    cout << A << endl;
}