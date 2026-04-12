#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(x) begin(x),end(x)
using LL=long long;
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const int INF = numeric_limits<int>::max();
int main()
{
    int N;
    cin >> N;
    cout << ( N * 800 ) - ( ( N / 15 ) * 200 ) << endl;
    return 0;
}