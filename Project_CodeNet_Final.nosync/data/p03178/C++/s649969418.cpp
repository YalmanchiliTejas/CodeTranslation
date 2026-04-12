#include <iostream>
#include <vector>
#include <fstream>
#include "bits/stdc++.h"
using namespace std;
#define bit(x, i) (x & (1 << i))          //select the bit of position i of x
#define lowbit(x) ((x) & ((x) ^ ((x)-1))) //get the lowest bit of x
#define max(a, b) (a < b ? b : a)
#define min(a, b) (a > b ? b : a)
#define abs(x) (x < 0 ? (-x) : x)   
#define IN(i, l, r) (l < i && i < r) //the next for are for checking bound
#define LINR(i, l, r) (l <= i && i <= r)
#define LIN(i, l, r) (l <= i && i < r)
#define INR(i, l, r) (l < i && i <= r)
#define clr(a, x) memset(a, x, sizeof(a)) //set elements of array to some value
#define char2Int(c) (c - '0')
#define lastEle(vec) vec[vec.size() - 1]
#define SZ(x) ((int)((x).size()))
#define REMAX(a, b) (a) = max((a), (b)) // set a to the maximum of a and b
#define REMIN(a, b) (a) = min((a), (b));
#define FOREACH(i, t) for (typeof(t.begin()) i = t.begin(); i != t.end(); i++) // traverse an STL data structure
#define ALL(c) (c).begin(), (c).end()                                          //handy for function like 
#define PRESENT(c, x) ((c).find(x) != (c).end())
#define CPRESENT(c, x) (find(ALL(c), x) != (c).end())
#define ll long long //data types used often, but you don't want to type them time by time
#define ull unsigned long long
#define us unsigned short
#define IOS ios_base::sync_with_stdio(0); //to synchronize the input of cin and scanf
#define INF 1001001001
#define PI 3.1415926535897932384626
#define mp make_pair
#define fi first
#define se second
#define ui unsigned int
//for vectors
#define pb push_back
typedef int elem_t;
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<pair<int, int>> vpi;
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<vpi> vvpi;
typedef pair<int, int> ii;
#define F(i, L, R) for (int i = L; i < R; i++) //next four are for for loops
#define FE(i, L, R) for (int i = L; i <= R; i++)
#define FF(i, L, R) for (int i = L; i > R; i--)
#define FFE(i, L, R) for (int i = L; i >= R; i--)
const int mod = 1e9 + 7;
namespace EU
{
void max_self(int &a, int b)
{
a = max(a, b);
}
}
void add_self(int &a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}
const int nax = 10123;
char k[nax];

int main() {
    scanf("%s", k);
    int D;
    scanf("%d", &D);
    int len = strlen(k);
    vvi dp(D, vi(2));
// dp[sum][smaller_already] - the number of ways to choose digits so far
// st the sum of digits modulo D is the sum and smaller already
// says wethere we already chosen some digit smaller than K
dp[0][0] = 1;
F(where, 0, len) {
    vvi new_dp(D, vi(2));
    F(sum, 0, D) {
        for(bool sm_already :  {false, true}) {
            F(digit, 0, 10) {
                if (digit > k[where] - '0' && !sm_already) {
                    break;
                }
                add_self(new_dp[(sum + digit) %D][sm_already || (digit < k[where] - '0')], dp[sum][sm_already]);
            }
        }
    }
    dp = new_dp;
}
    int answer = (dp[0][false] + dp[0][true]) % mod;
    --answer;
    if(answer == -1) {
        answer = mod - 1;
    }
    printf("%d\n", answer);
    
}