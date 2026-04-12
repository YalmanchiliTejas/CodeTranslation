#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    char RGB[3];
    cin >> RGB[0] >> RGB[1] >> RGB[2];

    int num = atoi(RGB);

    if(num % 4 == 0)cout << "YES";
    else cout << "NO";
    cout << endl;
}