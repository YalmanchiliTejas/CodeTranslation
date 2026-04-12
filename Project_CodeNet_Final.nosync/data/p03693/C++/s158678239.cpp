#include <bits/stdc++.h>

template <
    typename TYPE,
    std::size_t SIZE>
std::size_t a_len(const TYPE (&array)[SIZE])
{
    return SIZE;
}

using namespace std;
using ll = long long int;
using vi = vector<ll>;

#define REPS(a, i, n) for (ll(i) = a; (i) < (n); ++(i))
#define REP(i, n) REPS(0, i, n)
#define ALL(x) (x).begin(), (x).end()

const int INF = 100001;

int a,b,c;


int main()
{
    cin >> a >> b >> c;
    int ans = 100*a + 10*b+c;
    if(ans%4){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }

}