#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define oo 1000000010

int main()
{
    string s;
    int a = 0, b = 0;
    cin >> s;
    for(int i=0; i<3; i++){
		if(s[i] == 'A') a++;
		else b++;
    }

    if(a && b) cout << "Yes";
    else cout << "No";

    return 0;
}
