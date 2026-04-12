#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int h[n];
    for(int i=0;i<n;i++) cin >> h[i];
    int total=1,o=h[0];
    for(int i=1;i<n;i++)
    {
        if(h[i]>=o)
        {
            o=h[i];
            total++;
        }
    }
    cout << total;
    return 0;
}