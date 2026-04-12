#include <iostream>
#include <functional>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>

using namespace std;
typedef long long int ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

ll gcd(ll a, ll b) { return b ? gcd(b,a%b) : a;}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
typedef pair <ll,ll> P;
ll MOD = 1000000007;

int main()
{
    char c;
    cin >> c;
    if (c == 'a' | c == 'e' | c == 'i' | c == 'o' | c == 'u') {
        cout << "vowel" << endl;
    } else {
        cout << "consonant" << endl;
    }
    return 0;
}
