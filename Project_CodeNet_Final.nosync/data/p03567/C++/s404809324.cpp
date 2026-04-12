#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    string s;
    cin >> s;
    if(s.find("AC") == -1) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}
