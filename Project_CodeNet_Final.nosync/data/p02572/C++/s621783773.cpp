#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<string>
#include<cmath>
#include<set>
#include<queue>
#include<deque>
#include<bitset>
#include<iomanip>
#include<cctype>
#include<map>
#include<cstring>
#include<bitset>
#include<cassert>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,a,b) for (int (i)=a;(i)<(b);(i)++)
#define all(x) (x).begin(),(x).end()

using namespace std;
using ll = long long int;

const int inf = 1001001000;
const long long int Inf = 1001001001001001000;



void print(vector<vector<int>> a){
	for (int i = 0; i < a.size(); i++)
	{
		for (int j=0;j<a[i].size();j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void print(vector<vector<long long int>> a){
	for (int i=0;i<a.size();i++){
		for (int j=0;j<a[i].size();j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void print(vector<int> a){
    int n = a.size();
    for (int j=0;j<n;j++) {
        if (j != n-1) cout << a[j] << " ";
        else cout << a[j] << endl;
    }
}

void print(vector<long long int> a){
    int n = a.size();
    for (int j=0;j<n;j++) {
        if (j != n-1) cout << a[j] << " ";
        else cout << a[j] << endl;
    }
}

void print(set<int> a){
	for (auto x:a)
		cout << x << " ";
	cout << endl;
}

//mod計算用のクラス
// ModInt a = {1,1000000007}みたいな定義もできる.
//modがデフォルト(1000000007)じゃない場合は(ModInt)a+(int)xみたいなものに注意.左のmodが使われる。デフォルトを書き換えれば大丈夫.
//「各メンバーに対して、コピーコンストラクターあるいは代入演算子を順に呼び出す」 という仕様になっている.
// (int)1 + (ModInt)10 みたいなことは出来ない.非メンバで定義する必要がある（と思う）.
class ModInt{
public:
    long long int x;
    long long int mod;
	ModInt(){}
    ModInt(long long int _x, long long int _mod = 1000000007){
        this->x = ((_x % _mod) + _mod) % _mod;
        this->mod = _mod;
    }
	ModInt operator-() const {
		return ModInt(-this->x, this->mod);
	}
	ModInt operator+(const ModInt &other) const {
		return ModInt(this->x + (other.x % this->mod), this->mod);
	}
	ModInt operator+=(const ModInt &other){
		*this = *this + other;
		return *this;
	}
	ModInt operator-(const ModInt &other) const {
		long long int res = this->x - (other.x % this->mod);
		if (res < 0) return ModInt(res + this->mod, this->mod);
		return ModInt(res, this->mod);
	}
	ModInt operator-=(const ModInt &other) {
		*this = *this - other;
		return *this;
	}
	ModInt operator*(const ModInt &other) const {
		return ModInt(this->x * (other.x % this->mod),this->mod);
	}
	ModInt operator*=(const ModInt &other) {
		*this = *this * other;
		return *this;
	}
	ModInt operator/(const ModInt &other) const {
		return ModInt(*this * other.inv());
	}
	ModInt operator/=(const ModInt &other) {
		*this = *this / other;
		return *this;
	}
	ModInt pow(long long int n) const {
		ModInt res(1, this->mod), a(this->x, this->mod);
		while (n){
			if (n & 1){
				res = res * a;
			}
			n >>= 1;
			a = a * a;
		}
		return res;
	}
	ModInt inv() const {
		return ModInt(this->pow(this->mod - 2));
	}
	void disp(){
		cout << this->x << endl;
	}
};
ostream& operator<<(ostream& stream, const ModInt m){
	stream << to_string(m.x);
	return stream;
}



int main()
{
	int n;
	ll mod = 1e9 + 7;
	cin >> n;
	vector<ModInt> a(n);
	rep(i,n){
		int t;
		cin >> t;
		a[i] = ModInt(t);
	}
	ModInt sowa(0), ans(0);
	rep(i,n){
		sowa += a[i];
	}
	rep(i, n)
	{
		sowa = sowa - a[i];
		ans += sowa * a[i];
	}
	cout << ans << endl;
	return 0;
}