#include"bits/stdc++.h"
using namespace std;

int main()
{
    int e[12];
    for(int i=0;i<12;i++)
        cin >> e[i];
    sort(e,e+12);
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(e[i*4]!=e[i*4+j+1]){
                cout << "no" << endl;
                return 0;
            }
    cout << "yes" << endl;
    return 0;
}

