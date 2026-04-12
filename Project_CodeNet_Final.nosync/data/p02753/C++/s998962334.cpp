#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string S;
    cin >> S;
    cout << ((S == "AAA" || S == "BBB") ? "No" : "Yes") << endl;
    return 0;
}