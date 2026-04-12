#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int main()
{
    int n;
    cin >> n;
    int c = n / 15;
    cout << n * 800 - c * 200 << endl;
}
