#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    string x;
    cin >> x;
    if(x[0]=='A'&&x[1]=='A'&&x[2]=='B') cout << "Yes" << endl;
    else if(x[0]=='A'&&x[1]=='B'&&x[2]=='A') cout << "Yes" << endl;
    else if(x[0]=='B'&&x[1]=='B'&&x[2]=='A') cout << "Yes" << endl;
    else if(x[0]=='B'&&x[1]=='A'&&x[2]=='B') cout << "Yes" << endl;
    else if(x[0]=='A'&&x[1]=='B'&&x[2]=='B') cout << "Yes" << endl;
    else if(x[0]=='B'&&x[1]=='A'&&x[2]=='A') cout << "Yes" << endl;
    else cout << "No" << endl;
}
