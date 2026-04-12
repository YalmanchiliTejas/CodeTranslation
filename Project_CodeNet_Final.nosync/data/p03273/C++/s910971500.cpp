#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
using namespace std;

template <typename X, typename T>
auto vectors(X x, T a) {
	return vector<T>(x, a);
}

template <typename X, typename Y, typename Z, typename... Zs>
auto vectors(X x, Y y, Z z, Zs... zs) {
	auto cont = vectors(y, z, zs...);
	return vector<decltype(cont)>(x, cont);
}

template<typename T>
ostream& operator << (ostream& os, vector<T>& v){
	rep(i,v.size()){ os << v[i] << (i == v.size() - 1 ? "" : " "); } return os;
}
template<typename T>
istream& operator >> (istream& is, vector<T>& v){
	for(T& x: v){ is >> x; } return is;
}

template <typename T>
class CompressCoordinate{
public:
	vector<T> a, c; // 圧縮した数列、ソートした数列
	CompressCoordinate(const vector<T>& arg){
		a = vector<T>(arg.size());
		c = arg;
		compress(c);
		rep(i,arg.size()){
			a[i] = lb(c, arg[i]);
		}
	}
	void compress(vector<T> &v) {
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(),v.end()),v.end());
	}
	int lb(const vector<T>& v, T num){
		return lower_bound(all(v), num) - v.begin();
	}
	int map(T a){
		return lb(c, a);
	}
};

int main(){
	int h, w;
	cin >> h >> w;

	vector<pair<int, int>> p;
	vector<int> x, y;
	rep(i,h){
		rep(j,w){
			char c;
			cin >> c;
			if(c == '#'){
				p.emplace_back(i,j);
				x.emplace_back(j);
				y.emplace_back(i);
			}
		}
	}

	CompressCoordinate<int> cx(x), cy(y);

	vector<vector<char>> m(cy.c.size(), vector<char>(cx.c.size(), '.'));
	rep(i,p.size()){
		m[cy.map(p[i].first)][cx.map(p[i].second)] = '#';
	}

	rep(i,m.size()){
		rep(j,m[0].size()){
			cout << m[i][j];
		}
		cout << endl;
	}
}
