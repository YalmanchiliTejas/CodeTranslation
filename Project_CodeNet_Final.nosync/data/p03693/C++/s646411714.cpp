#include<iostream>

#include<string>
#include <algorithm> 
using namespace std;

int main()
{
    string a,b,c;
    cin >> a >> b >> c;

    if (stoi(a+b+c)%4 == 0) cout << "YES" << endl;
    else     cout << "NO" << endl;

}