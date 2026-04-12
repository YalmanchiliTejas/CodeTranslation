#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <utility>
#include <functional>
#include <set>
#include <map>
#include <bitset>
#include <list>

using namespace std;


#define INF pow(10, 9)
// typedef priority_queue<tuple<int,int,int>, vector< tuple<int, int, int> >, greater< tuple<int, int, int> > > PQ;

typedef long long int ll;




int main(void)
{

    int tmp_d;
    cin >> tmp_d;
    const int N = tmp_d;
    int Array[N];
    ll Sum = 0;
    ll mod = pow(10, 9) + 7;
    for(int i=0; i<N; i++)
    {
        cin >> Array[i];
        Sum = (Sum+Array[i])%mod;
    }

    ll Total = 0;
    for(int i=0; i<N-1; i++)
    {
        Sum = (Sum-Array[i])%mod;
        if(Sum<0) Sum += mod;
        Total = (Total+Array[i] * Sum) % mod;
    }

    cout << Total << endl;






    return 0;
}
