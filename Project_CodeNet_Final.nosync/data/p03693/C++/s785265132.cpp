#include<iostream>
#include<cmath>
using namespace std;


int main()
{
    int s[3], sum = 0;
    for (int i = 0; i < 3; i++)
    {
        cin >> s[i];
        sum += s[i] * pow(10, 2 - i);
    }
    if (sum % 4 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
    
}