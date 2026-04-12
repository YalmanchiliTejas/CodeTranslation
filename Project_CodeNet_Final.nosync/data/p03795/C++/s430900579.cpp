#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, a, b) for(int i = (a); i < (b); ++i)

int main()
{
    int N;
    cin >> N;
    cout << N*800 - N/15 * 200 << endl;
    return 0;
}