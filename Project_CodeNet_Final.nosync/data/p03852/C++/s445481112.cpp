#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define FOR(i,a,b) for(int i=(a);i<(int)(b);++i)
#define rep(i,n) FOR(i,0,n)
#define OUT(x) cout<<(x)<<"\n"
const int INF = 114514;


int main(){
    char s;
    cin >> s;
    string vv="aiueo";
    rep(i, vv.size()) if(vv[i] == s) {
        OUT("vowel");
        return 0;
    }
    OUT("consonant");

    return 0;
}