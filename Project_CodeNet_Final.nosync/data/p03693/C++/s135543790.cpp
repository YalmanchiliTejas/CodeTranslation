#include <bits/stdc++.h>

using namespace std;

typedef unsigned short ushort;typedef unsigned int uint;typedef long long ll;typedef unsigned long long ull;
template <typename T> ostream &operator<<(ostream &cout, vector<T> &a){for(size_t i = 0; i < a.size(); ++i) cout << a[i] << " "; return cout;}
template <typename T> ostream &operator<<(ostream &cout, vector<vector<T> > &a){for(size_t i = 0; i < a.size(); ++i) cout << a[i] << endl; return cout;}

int main()
{
    ios_base::sync_with_stdio(0);
    int a, b;
    cin >> a;
    cin >> a >> b;
    if((10 * a + b) % 4){
        cout << "NO" << endl;
    }else
        cout << "YES" << endl;
    return 0;
}
