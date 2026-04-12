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
	int n;
	cin >> n;
	map<char, int> res;
	rep(i,n){
		map<char, int> temp;
		string s;
		cin >> s;
		rep(j,s.size()){
			temp[s[j]]++;
		}
		if (i == 0){
			res = temp;
		}else {
			for (char c = 'a'; c <= 'z'; c++)
			{
				res[c] = min(res[c], temp[c]);
			}
		}

		
	}
	string ans = "";
	for (char c = 'a'; c <= 'z';c++){
		ans += string(res[c], c);
	}
	cout << ans << endl;

	return 0;
}
