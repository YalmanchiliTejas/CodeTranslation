#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    int b;
    cin >> b;
    int n[b];
    for(int i = 0; i < b; i++)
    {
        cin >> n[i];
    }
    if(b % 2 == 0)
    {
        for(int i = b-1; i > 0; i-=2)
        {
            cout << n[i] << ' ';
        }
        for(int i = 0; i < b; i+=2)
        {
            cout << n[i] << ' ';
        }
    }
    else
    {
        for(int i = b-1; i >= 0; i-=2)
        {
            cout << n[i] << ' ';
        }
        for(int i = 1; i < b; i+=2)
        {
            cout << n[i] << ' ';
        }
    }
}
