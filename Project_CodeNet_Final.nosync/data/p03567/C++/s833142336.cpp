#include <iostream>
#include <string>
using namespace std;

int main()
{
    string temp = "";
    cin >> temp;

    for (int i = 0; i < temp.size() - 1;i++)
    {
        if(temp[i]=='A'&&temp[i+1]=='C')
        {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
    return 0;
}