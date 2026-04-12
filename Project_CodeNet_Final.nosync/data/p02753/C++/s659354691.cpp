#include <iostream>
#include <string>

using namespace std;

int main()
{
    string S;
    cin >> S;

    string answer = (S == "AAA" || S == "BBB") ? "No" : "Yes";
    cout << answer << endl;
}