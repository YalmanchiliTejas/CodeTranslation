#include<iostream>
#include<algorithm>
#include<vector>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main()
{
    string s;
    cin >> s;
    if(s == "a" || s == "e" || s == "i" || s == "o" || s == "u")
    {
        cout << "vowel" << endl;
    }
    else
    {
        cout << "consonant" <<endl;
    }
}
