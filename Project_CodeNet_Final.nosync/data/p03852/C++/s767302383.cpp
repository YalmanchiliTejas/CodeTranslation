#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <map>
#include <cmath>
#include <limits>
#include <iomanip>
#include <queue>
#include <bitset>
#define ll long long int
#define ld long double
#define rep(i,n) for(int i = 0;i < n;i++)
#define rep1(i,n) for(int i = 1;i < n;i++)
#define co(x) cout << x << endl
#define cosp(x) cout << x << " "
#define all(x) x.begin(),x.end()
#define P pair<ll,ll>
#define pb push_back
#define mp make_pair
#define MOD 1000'000'007
#define INF 1ll << 60
#define PI 3.14159265359

using namespace std;
int main(){
    
    char c;
    cin >> c;
    if(c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o') cout << "vowel" << endl;
    else cout << "consonant" << endl;
    return 0;
}