#include "bits/stdc++.h"
using namespace std;
int n;
int m;
vector < pair < int , int > > res;
int main()
{
            ios_base::sync_with_stdio(false);
            cin.tie(0);
            cout.tie(0);
            int a,b,c;
            cin >> a >> b >> c;
            if((10 * b + c) % 4 == 0)
                cout << "YES"  << endl;
            else
                cout << "NO" << endl;
            return 0;
}
