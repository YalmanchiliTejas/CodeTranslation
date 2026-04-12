#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    string S;
    cin >> S;

    if ((S == "AAA") || (S == "BBB")) cout << "No";
    else cout << "Yes";

    return 0;
}
