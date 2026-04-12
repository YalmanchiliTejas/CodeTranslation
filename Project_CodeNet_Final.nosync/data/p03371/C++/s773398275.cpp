#include <bits/stdc++.h>
using namespace std;

typedef long long  ll;

ll MOD = 1000000007;
ll INF = 90000000000000000;
double PI = 3.1415926535;

template<typename T>
void remove(std::vector<T>& vector, unsigned int index)
{
    vector.erase(vector.begin() + index);
}

using Graph = vector<vector<pair<ll,ll>>>;


int main(){
 int A,B,C,X,Y;
 cin >> A >> B >> C >> X >> Y;
 int d = A * X + B * Y,e = 2 * C * X + max(0,Y-X) * B,f = 2 * C * Y + max(0,X-Y) * A;
 //cout <<  d << ' ' << e << ' ' << f << endl;
 cout << min({d,e,f}) << endl;
}
