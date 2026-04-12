#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <deque>
#include <list>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <fstream>
#include <functional>
#include <bitset>

using namespace std;


#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int (i)=(n); (i)>=(0); (i)--)
#define SIZE(x) ((int)(x).size())
#define GCD(a, b) int gcd(int a,int b){return b?gcd(b,a%b):a;}
#define QP(a, b) int qp(int a,ll b){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}


template<typename T> void chmax(T &a, T b) {a = max(a, b);}
template<typename T> void chmin(T &a, T b) {a = min(a, b);}
template<typename T> void chadd(T &a, T b) {a = a + b;}

typedef pair<int, int> pii;
typedef long long ll;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const ll INF = 1001001001001001LL;
const ll MOD = 1000000007LL;


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    char c; cin >> c;
    if(c=='a' || c=='i' || c=='u' || c=='e' || c=='o') cout << "vowel";
    else cout << "consonant";
    cout << endl;
    return 0;
}




