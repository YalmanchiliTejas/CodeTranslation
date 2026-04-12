#include <bits/stdc++.h>
#define ALL(T) (T).begin(), (T).end()
#define pb push_back
#define mp make_pair
typedef long long ll;
using namespace std;
ll intmax = (1LL<<32)-1;
const int INF = 1e9 + 5;


class fastio{
public:
	fastio(){
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
	}
} __fastio;

template <typename T>
T abs(T x){
	if(x < 0) return -x;
	else return x;
}

template <typename T>
void swap(T &a, T &b){
	T temp;
	temp = a;
	a = b;
	b = temp;
}

const int MX = 2001;

void solve() {
	
}

int main() {
	string s;
	bool answer = false;
	cin >> s;
	for(int i=0; i<3; i++) {
		for(int j=i+1; j<3; j++) {
			if(s[i] != s[j])
				answer = true;
		}		
	}
	cout << ((answer)?("Yes\n"):("No\n"));
}
