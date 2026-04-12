#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cctype>
#include <climits>
#include <bitset>
#include <utility>
using namespace std;
typedef long double ld;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<pair<int,int>> vpii;
typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;
typedef vector<vector<string>> vvs;
#define rep(i,n) for(int i=0;i<n;i++)
#define fin(ans) cout<<(ans)<<endl
#define P 1000000007
#define STI(s) atoi(s.c_str())//string to int
#define mp(p,q) make_pair(p,q)
#define Sort(a) sort(a.begin(),a.end())
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
const int INF = INT_MAX;
const long long LLINF = 1LL<<60;
//g++ -std=c++1z temp.cpp
//./a.exe
int digit(int a){
    int count = 0;
    for (int i = 0; i < a; i++)
    {   if (a == 0)
        {
            break;
        }else
        {
            a = a/10;
            count++;
        }     
    }
    return count;
}
//pow(x,n) == x^n

int main(void){ios::sync_with_stdio(false);cin.tie(0);
//////////////////////////////////////////////////////

int x,y,z,sum = 0,l;
cin >> x >> y >> z;
l = x-z;
sum = y+z;

    cout << l / sum << endl;







//////////////////////////////////////////////////////
return 0;}