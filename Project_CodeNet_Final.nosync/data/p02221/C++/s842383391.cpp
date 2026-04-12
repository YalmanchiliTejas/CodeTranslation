#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
using namespace std;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

Int n;
string s;
Int p[1 << 18];
Int winner[19][1 << 18];
Int fight(Int a, Int b){
    if(a < b)swap(a, b);
    if(s[a-b -1] == '0')return b;
    else return a;
}

int main(){
    cin >> n;
    cin >> s;
    for(int i = 0;i < (1<<n);i++){
        cin >> p[i];
        winner[0][i] = p[i];
    }
    for(int i = 1;i <= n;i++){
        for(int j = 0;j < (1<<n);j++){
            winner[i][j] = fight(winner[i-1][j], winner[i-1][(j + (1 << (i-1))) % (1<<n)]);
            if(i == n)cout << winner[i][j] << endl;
        }
    }
    return 0;
}
