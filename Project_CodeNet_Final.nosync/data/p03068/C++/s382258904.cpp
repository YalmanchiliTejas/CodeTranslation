#include<bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n ; i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define ALL(obj) (obj).begin(), (obj).end() //イテレータの簡略化（コンテナじゃないと使えない）
using namespace std;
typedef long long ll; // long longをllでかけるようにした
const int INF = 100100100;

// 最大公約数
int gcd(int a, int b)
{
    int c;

    if (a < b) {
        a+=b; b=a-b; a-=b;
    }

    while (b != 0) {
        c = a % b;
        a = b;
        b = c;
    }

    return a;
}

// 最小公倍数
int lcm( int m, int n )
{
	// 引数に０がある場合は０を返す
	if ( ( 0 == m ) || ( 0 == n ) )
		return 0;
	
	return ((m / gcd(m, n)) * n); // lcm = m * n / gcd(m,n)
}

/* 二分探索 */

//indexが条件を満たすかどうか
bool isOK(int index, int key, vector<int> a) {
    if (a[index] >= key) return true;
    else return false;
}

//汎用的な二分探索のテンプレ
int meguru_binary_search(int key, vector<int> A){
    int ng = -1; // lowerの時は-1, upperの時は(int)A.size() //「index = 0」が条件を満たすこともあるので、初期値は -1
    int ok = (int)A.size(); // lowerの時は(int)A.size(), upperの時は-1 // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

    /* どんな二分探索でもここの書き方を変えずにできる！ */
    while(abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        if(isOK(mid, key, A)) ok = mid;
        else ng = mid;
    }

    /* left は条件を満たさない最大の値、right は条件を満たす最小の値になっている(lowerだと) */
    return ok;
}
/* lower_boundとかでイテレータから配列の添え字を求めたいとき(lower_bound(v.begin(),v.end(),hoge)-v.begin())というようにする */
//distanceも使える

//三項演算子 ?:

int main(void){
    string s;
    int n, k;
    cin >> n >> s >> k;
    char moji = s[k - 1];
    REP(i, n) {
        if(s[i] != moji) s[i] = '*';
    }
    cout << s << endl;
    
}