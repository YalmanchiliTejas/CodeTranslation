#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<numeric>
#include<map>
#include<set>
#include<stack>
#include<queue>

#define reps(i,j,k) for(int i=(j);i<(k);i++)
#define rep(i,j) reps(i,0,j)
#define fs first
#define sc second
#define pb push_back
#define mk make_pair

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

template<class S,class T>
ostream &operator<<(ostream &out, const pair<S,T> p){
	return out << "(" << p.fs << ", " << p.sc << ")";
}

template<class T>
ostream &operator<<(ostream &out, const vector<T> &v){
	out << "{";
	rep(i,v.size()) out << v[i] << ", ";
	return out << "}" << endl;
}

int main(){
	string s;
	cin >> s;
	string ac = "AC";
	rep(i, s.length() - 1){
		bool f = false;
		rep(j, 3){
			if (j == 2) {
				f = true;
				break;
			}
			if(s[i+j] != ac[j]) break;
		}
		if (f){ cout <<"Yes" << endl;return 0;}
	}
	cout << "No" << endl;

	return 0;
}
