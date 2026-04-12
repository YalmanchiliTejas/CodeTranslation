#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < n; i++)
#define REP(i, n) for(ll i = 1; i < n + 1; i++)
#define PI 3.14159265359
#define EPS 0.0000000001
#define MOD 1000000007
//cout << std::fixed << std::setprecision(15) << y << endl;


int main(){
    ll n;
    cin >> n;

    ll alphabet[26];
    ll alphabetS[26];
    rep(i, 26){
        alphabet[i] = 100;
    }

    string s;
    rep(i, n){
        rep(j, 26){
            alphabetS[j] = 0;
        }
        cin >> s;

        rep(j, s.size()){
            alphabetS[s[j] - 'a']++;
        }
        rep(j, 26){
            alphabet[j] = min(alphabet[j], alphabetS[j]);
        }
    }

    rep(i, 26){
        rep(j, alphabet[i]){
            cout << (char)('a' + i);
        }
    }
    cout << endl;

    return 0;
}