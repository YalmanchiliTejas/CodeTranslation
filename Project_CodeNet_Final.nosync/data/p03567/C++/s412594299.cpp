#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>
using namespace std;

int main(void)
{
    string s;
    cin >> s;
    if(s.find("AC") != -1){cout << "Yes" << endl;}
    else{cout << "No" << endl;}
    return 0;
}