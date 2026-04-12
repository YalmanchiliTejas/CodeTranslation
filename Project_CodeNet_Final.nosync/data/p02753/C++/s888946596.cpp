//52行目から編集
#include <iostream>
#include <limits.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int> > vvi;
typedef vector<vector<ll> > vvl;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;

template<class T> bool chmin(T& a,T b){if(a > b){a = b;return true;}else return false;}
template<class T> bool chmax(T& a,T b){if(a < b){a = b;return true;}else return false;}
///////////////////////////////////////////////////////////

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(20);
    string s;cin >> s;
    if(s == "AAA" || s == "BBB"){
        cout << "No" << '\n';
    }else{
        cout << "Yes" << '\n';
    }
    return 0;
}
/*
 *!!CHECK!! 
 * intの掛け算をしてる場合：overflowは大丈夫？
 * 制約の下限・上限は大丈夫？
 * 木構造は一直線にした時TLEしない？
 * */
