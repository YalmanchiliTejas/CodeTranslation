#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    string s1 = "AC";
    string s2;
    cin >> s2;
    int x = s2.find(s1);
    if(x == -1) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}
