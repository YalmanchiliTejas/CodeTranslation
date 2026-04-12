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
 
template<typename T>
void print1d(vector<T> a){
    for (auto x:a){
        cout << x << " ";
    }
    cout << endl;
}
 
template<typename T>
void print2d(vector<vector<T>> a){
	for (auto v:a){
		for (auto x:v){
			cout << x << " ";
		}
		cout << endl;
	}
}

template<typename T>
void print(T a){
	for (auto x:a){
		cout << x << " ";
	}
	cout << endl;
}

int main()
{
	ll a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	ll ans = Inf;
	rep(i, max(2 * x + 1, 2 * y + 1))
	{
		ll na = max(0LL,x - i / 2);
		ll nb = max(0LL,y - i / 2);
		ans = min(ans, na * a + nb * b + i * c);
	}
	cout << ans << endl;
}
