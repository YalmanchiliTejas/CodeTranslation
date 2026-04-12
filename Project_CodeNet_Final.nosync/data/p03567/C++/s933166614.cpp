#include <bits/stdc++.h>
using namespace std;

void Yes(bool f){cout<<(f?"Yes":"No")<<endl;}

int main()
{
    string S;
    cin >> S;

    Yes(S.find("AC") != string::npos);
}
