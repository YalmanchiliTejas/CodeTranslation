#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a;
    cin >> a;
    int A = 0, B = 0;
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] == 'A')
            A++;
        else if(a[i] == 'B')
            B++;
    }
    if(A == 0 || B == 0)
        cout << "No" << endl;
    else
        cout <<"Yes" << endl;
    return 0;
}
