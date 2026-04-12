#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <queue>
#include<bitset>
#include <set>

#define REP(i, n) for (long long i = 0; i < (n); i++) 
typedef long long ll;
static const ll INF = 1000000000000000000LL;
using namespace std;

const int MOD = 1000000007;

//abc134_e E - Sequence Decomposing 
//a[i]とa[j] が同じ色なら、a[i] < a[j] を満たす
//用いる色の数を最小にする
// 2 1 4 5 3 -> 145  23 の 2色
// 245 13でもよい
// 後ろから見て、現在の最小の値を保存したほうがよい?


int main(){
    int N;
    cin >> N;
    vector <ll> a(N);
    REP(i,N)
    {
        cin >> a[i];
    }
    vector <int> v;
    multiset<ll> s;
    int res = 1;
    s.insert(a[0]);
    s.insert(MOD);

    v.push_back(a[0]);
    for(int i = 1; i < N; ++i)
    {
        auto itr = s.lower_bound(a[i]);

        if(itr == s.begin())
        {
            s.insert(a[i]);
            ++res;
        }
        else
        {
            --itr;
            s.erase(itr);
            s.insert(a[i]);
        }

    }
        
    cout << res << endl;
    return 0;
}

