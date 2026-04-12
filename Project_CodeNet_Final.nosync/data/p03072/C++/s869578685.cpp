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
#include<cstring>

using namespace std;

#ifdef LDEBUG
#define debug(x) cout << #x << ":" << x << endl
#else
#define debug(...)
#endif

#define REP(i,n) for(int i=0; i<n; ++i)

typedef unsigned long long u64;
typedef long long i64;

int n;
int h[100];

int main(){
        cin.tie(0);
        ios::sync_with_stdio(false);

        cin >> n;

        REP(i,n)
                cin >>  h[i];

        int r = 0;

        int m = 0;
        REP(i,n) {
                if (m <= h[i]){
                        m = h[i];
                        r++;
                }
        }

        cout << r << endl;


        return 0;
}
