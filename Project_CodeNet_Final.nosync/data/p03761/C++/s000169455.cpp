#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#include <cstring>
#include <cmath>
using namespace std;
#define MAXA 1001
#define MAXB 1001
#define MAXH 1000000001
#define MAXW 405
#define INF 5000
#define MAXN 51
#define MAXM 200001
#define MAXK 200002
#define MAXP 1000001
#define MOD 1000000007
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
ll N;
ll A[MAXN];


int main(){
    int n;
    cin >> n;
    string s[MAXN];
    for(int i = 0;i < n;i++){
        cin >> s[i];
    }
    map<char, int> m[MAXN];
    for(int i = 0;i < n;i++){
        for(int j = 0;j < s[i].length();j++){
            m[i][s[i][j]]++;
        }
    }
    map<char, int> ans;
    int res = 0;
    string best = "";
    for(char c = 'a';c <= 'z';c++){
        ans[c] = INF;
        for(int i = 0;i < n;i++){
            if(ans[c] > m[i][c]) ans[c] = m[i][c];
        }
        res += ans[c];
        for(int i = 0;i < ans[c];i++){
            best += c;
        }
    }
    cout << best << endl;

    
    return 0;
}