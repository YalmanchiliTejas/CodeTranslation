//
// Created by Ryuta Kremer on 2018-12-08.
//

//uncorrect

#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define REP(i,b) FOR(i,0,b)
#define RFOR(i,a,b) for (int i = a-1; i >= b; i--)
#define RREP(i,a) RFOR(i,a,0)
#define REPALL(i,v) for (int i = 0; i < v.size(); i++)
#define SORT(v) sort(v.begin(), v.end())
#define MIN_ELEMENT(v) min_element(v.begin(), v.end())
#define MAX_ELEMENT(v) max_element(v.begin(), v.end())
#define COUNT(v,n) count(v.begin(), v.end(), n);
typedef long long ll;
typedef unsigned long long ull;
const int INF = 1e7;
const ll MOD = 1e9 + 7;

ull A(ull num, ull x)
{
    if (x == 0) {
        return 0;
    }
    if (num == 1 && x == 1) {
        return 0;
    } else if (num == 1 && x == 2) {
        return 1;
    } else if (num == 1 && x == 3) {
        return 2;
    } else if (num == 1 && x == 4) {
        return 3;
    } else if (num == 1 && x == 5) {
        return 3;
    }
    //cout<<num<<endl;
    ull l = (1ull << (num + 1)) - 3;
    if (x == 2 * l + 3) {
        return A(num-1, l) * 2 + 1;
    } else if (x > l + 2) {
        return A(num-1, l) + 1 + A(num-1, x-l-2);
    } else if (x == l + 2){
        return A(num-1, l) + 1;
    } else {
        return A(num-1, x-1);
    }
}

int main()
{
    ull n, x;
    cin>>n>>x;

    ull ans = A(n,x);

    cout<<ans<<endl;

    return 0;
}
