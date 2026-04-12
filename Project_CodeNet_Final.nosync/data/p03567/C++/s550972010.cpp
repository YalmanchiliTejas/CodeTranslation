#include <bits/stdc++.h>
using namespace std;
int i=0;
char AC[10];
int main()
{
    cin.getline(AC,10);
    for(int i=0;i<10;i++)
    {
        if(AC[i]=='A'&&AC[i+1]=='C')
        {
            cout<<"Yes";
            return 0;
        }
    }
    cout<<"No";
    return 0;
}