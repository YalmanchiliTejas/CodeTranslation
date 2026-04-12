#include<iostream>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    int n,k;
    cin >> n;
    cin >> s;
    cin >> k;

    // string c = s[c];

    for (int i = 0; i < n; i++)
    {
        if(s[k-1] != s[i]){
            s[i] = '*';
        }
    }
    
    cout << s << endl;

    return 0;
}
