#include<bits/stdc++.h>
using namespace std;

int main()
{
    string sta;

    cin >> sta;

    bool ans = false;
    char aorb;
    if (sta[0] != sta[1]) { ans = true; }
    if (sta[0] != sta[2]) { ans = true; }
    if (sta[1] != sta[2]) { ans = true; }

    if (ans)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    
}