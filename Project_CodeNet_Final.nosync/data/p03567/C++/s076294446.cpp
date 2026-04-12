#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int len=s.size();
    int flag=0;
    for(int i=0;i<len-1;i++)
    {
        if(s[i]=='A'&&s[i+1]=='C')
            flag=1;
    }
    if(flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
