#include<iostream>
using namespace std;
int main()
{
    int n, s = 0, h[100];
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    for(int i = 0; i < n; i++)
    {
        int k = 0;
        for(int j = 0; j <= i; j++)
        {
            if(h[j] > h[i])
                k++;
        }
        if(k == 0)
            s++;
    }
    cout << s;
    return 0;
}