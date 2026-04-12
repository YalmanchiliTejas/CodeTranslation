#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int m, n, i, j;
    int o = 0;
    int p = 0;
    cin >> m;
    for (i=0;i<m;i++){
        cin >> n;
        if(n >= o){
            p = p + 1;
            o = n;
        }
    }
    cout << p;
    return 0;
}