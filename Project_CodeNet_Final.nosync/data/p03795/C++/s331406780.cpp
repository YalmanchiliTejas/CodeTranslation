#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, temp=0, temp2=0;
    cin >> N;
    temp = N * 800;
    temp2 = N / 15;
    cout << temp - temp2 * 200 << endl;
}