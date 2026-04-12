// Example program
#include <iostream>
#include <string>
using namespace std;
int main()
{
     int n, k;
     string s;
     cin >> n >> s >> k;
     if(k > n)
     {
         cout << s;
         return 0;
         }
    for(int i = 0;i<n;i++)
    {
        if(s[i] == s[k-1])
        cout << s[i];
        else
        cout << "*";
    }
}
