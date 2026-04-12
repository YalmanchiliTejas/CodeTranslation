#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"
#include "ctime"

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(begin, i, end) for (int i = begin; i < (int)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1000000007;

int main()
{
    char a;
    cin >> a;
    vector<ll> b(5);
    b = {'a', 'e', 'o', 'u', 'i'};
    rep(0, i, 5)
    {
        if (b.at(i) == a)
        {
            cout << "vowel" << endl;
            return 0;
        }
    }

    cout << "consonant" << endl;
}