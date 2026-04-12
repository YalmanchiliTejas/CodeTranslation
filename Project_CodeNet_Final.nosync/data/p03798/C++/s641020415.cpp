#include <iostream>
#include <sstream>
#include <stack>
#include <iomanip>
#include <numeric>
#include <string>
#include <cstring>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <queue>
#include <cmath>

#define BEGIN(x) x.begin()
#define END(x) x.end()
#define ALL(x) BEGIN(x), END(x)
#define PAIR make_pair
#define VEC(type) vector<type >
#define endl '\n'

#define FOR(i, A, B) for(auto i = (A);i != (B); i++)
#define FORD(i, A, B) for(auto i = (A);i != (B); i--)

#define READRANGE(begin, end) FOR(it, begin, end) cin >> *it
#define READVEC(V) READRANGE(BEGIN(V), END(V))

using namespace std;

typedef long long lint;
typedef pair<int, int> Pii;
typedef pair<int, lint> Pil;
typedef pair<lint, lint> Pll;
typedef pair<lint, int> Pli;

template<class U, class V>
istream& operator >>(istream& in, pair<U, V>& pr) {
    return in >> pr.first >> pr.second;
}

// ---- BEGIN LIBRARY CODE ----
// ---- END LIBRARY CODE ----
void io_init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
};

char guess(char ans, char before, char animal)
{
    char other = before == 'S' ? 'W' : 'S';
    if (animal == 'S') {
        return ans == 'o' ? before : other;
    } else {
        return ans == 'x' ? before : other;
    }
};

bool check(int i, string& Answer, const string& S)
{
    char now = guess(S[i - 1], Answer[i - 2], Answer[i - 1]);
    if (i == S.size()) {
        if (now != Answer[0])
            return false;

        now = guess(S[0], Answer.back(), Answer[0]);
        return now == Answer[1];
    }

    Answer[i] = now;
    return check(i + 1, Answer, S);
};

int main(int argc, char **argv)
{
    io_init();

    // Actual program code starts here.
    int N;
    string S;
    cin >> N >> S;
    string Answer(N, '_');
    for (char c1 : "SW")
        for (char c2 : "SW") {
            Answer[0] = c1;
            Answer[1] = c2;
            if (check(2, Answer, S)) {
                cout << Answer << endl;
                return 0;
            }
        }

    cout << -1 << endl;
    return 0;
};