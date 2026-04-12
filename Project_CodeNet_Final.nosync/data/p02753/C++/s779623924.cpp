#include<iostream>
using namespace std;
int main()
{
    string s;
    int a=0;
    int b=0;
    cin >> s;
    for(int i=0;i<3;i++)
    {
      if (s[i] == 'A') ++a;
      else ++b;
    }

    if (a==3||b==3)cout << "No" << endl;
    else cout << "Yes" << endl;
      return 0;
}
