#include <bits/stdc++.h>


using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    int n;cin >> n;
    if(n == 3 || n == 5 || n == 7)return cout << "YES",0;
    cout << "NO";
    return 0;
}
