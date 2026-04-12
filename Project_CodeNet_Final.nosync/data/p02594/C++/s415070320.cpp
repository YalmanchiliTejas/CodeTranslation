/**
 * author: BueVonHun 🐼🎋
 * More Info: https://github.com/Bue-von-hon
**/

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <cstring>
#include <cmath>

typedef long long ll;
using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
#define m_p make_pair
#define pii pair<int,int>
#define piii pair<int,pii>
#define vt vector
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

template <class T> T _min(T a,T b){return (a<b ? a : b);}
template <class T> T _max(T a,T b){return (a>b ? a : b);}
template<class T> void read(T& x) {cin >> x;}

int test_case;
int main(void) {
    fast_cin();

    read(test_case);

    if (test_case>=30)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
