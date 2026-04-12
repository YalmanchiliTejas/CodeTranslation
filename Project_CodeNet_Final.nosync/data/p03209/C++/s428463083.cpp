#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
#include<numeric>
#include<utility>
#include<complex>
#include<memory>
#include<functional>

using namespace std;

#ifdef LDEBUG
#define debug(x) cout << #x << ":" << x << endl
#else
#define debug(...)
#endif

#define bzero(m)  memset(m,0,sizeof(m))
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

typedef unsigned long long u64;
typedef long long i64;

u64 p[100];
u64 b[100];

void pre(int k){
        if (b[k] > 0) return;

        b[k] = 2*b[k-1] + 3;
        p[k] = 2*p[k-1] + 1;
}

u64 eat(int level, u64 k){
        if (k > b[level]) k--;

        if (level == 0) return 1;
        if (k == 1)  return 0;

        if (k == 2 + b[level-1])
                return p[level-1] + 1;

        if (k > 2 + b[level-1]){
                return p[level-1] + 1 + eat(level-1, k-2-b[level-1]);
        }

        return eat(level-1, k-1);
}

int main(){
        cin.tie(0);
        ios::sync_with_stdio(false);

        int n;
        u64 x;
        cin >> n >> x;

        p[0] = 1;
        b[0] = 1;

        REP(i,51)
                pre(i);

        cout << eat(n, x);

        return 0;
}
