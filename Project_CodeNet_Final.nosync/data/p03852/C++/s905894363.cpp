#include <bits/stdc++.h>
#include <sstream>
using namespace std;

typedef long long ll;
//loop
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
//STL
#define ALL(x) (x).begin(),(x).end()
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))

//const
#define MOD 1000000007 //10^9+7:合同式の法

//acronym
#define PB push_back //vectorヘの挿入
#define MP make_pair //pairのコンストラクタ
#define F first //pairの一つ目の要素
#define S second //pairの二つ目の要素

void Main() {
    string c;
    cin >> c;
    if (c == "a" || c == "e" || c == "i" || c == "o" || c == "u") {
        cout << "vowel" << endl;
    } else {
        cout << "consonant" << endl;
    }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	Main();
	return 0;
}
