#include <bits/stdc++.h>
#include<iostream>
using namespace std;



int main(void)
{
    int x;
    cin >> x;
    switch(x){
        case 3:
        case 5:
        case 7:
            cout << "YES" << endl;
            break;
        default:
            cout << "NO" << endl;
            break;
    }
    return 0;
}