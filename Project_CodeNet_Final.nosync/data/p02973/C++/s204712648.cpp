#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <queue>

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

    v.push_back(a[0]);
    for(int i = 1; i < N; ++i)
    {

        if(v[0] >= a[i])
        {
            auto it = v.begin();
            it = v.insert(it, a[i]);
        }
        else
        {
            //挿入位置を二分探索で見つける
            int p = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
            v[p-1] = a[i];
            

        }

    }
    //for(auto t: v)
    //{
    //    cout << t << endl;
    //}
        
    int res;
    res = v.size();
    cout << res << endl;
    return 0;
}

