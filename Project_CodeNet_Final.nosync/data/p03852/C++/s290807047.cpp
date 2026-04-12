/* Author rumoisen */
/* created 2018/11/17 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <iomanip>
#include <numeric>
#include <cmath>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define SORT(c) sort((c).begin(), (c).end())
#define INF (ll)1e18
#define MOD (ll)1e9 + 7
#define pb push_back

void no() { cout << "No" << endl;exit(0);}
void yes() { cout << "Yes" << endl;exit(0);}
void No() { cout << "NO" << endl;exit(0);}
void Yes() { cout << "YES" << endl;exit(0);}

typedef long long ll;
typedef long long int llt;
typedef pair<int, int> P;
typedef vector<int> V;
typedef map<int, int> M;

using namespace std;

int main()
{
    char s;
    cin >> s;
    bool flag = false;
    if(s=='a'||s=='i'||s=='u'||s=='e'||s=='o')
        flag = true;
    if(flag)
        cout << "vowel" << endl;
        else
            cout << "consonant" << endl;
    return 0;
}