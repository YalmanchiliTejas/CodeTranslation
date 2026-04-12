#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dd;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

#define FOR(i,a,b) for (int (i) = (a); (i) < (b); (i)++)
#define DOW(i,b,a) for (int i = (b); i >= (a); i--)
#define pb(a) push_back(a)
#define ALL(a) (a).begin(),(a).end()
#define fi first
#define se second

template<typename T>
void print_array(T* arr, int num) {
   FOR(i, 0, num) cout << arr[i] << ' ';
   cout << endl;
}

template<typename T> 
void print_vector(vector<T> vec) {
   FOR(i,0,vec.size()) cout << vec[i] << ' ';
   cout << endl;
}

int n,x;
deque<int> de;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    //freopen("test.txt", "r", stdin);
    cin >> n;
    FOR(i,0,n) {
    	cin >> x;
    	if (i % 2) de.push_front(x);
    	else de.push_back(x);
    }
    if (n % 2 == 0) {
    	while (!de.empty()) {
    		int a = de.front();
    		cout << a << " ";
    		de.pop_front();
    	} 
    } else {
		while (!de.empty()) {
			int a = de.back();
			cout << a << " ";
			de.pop_back();
    	}
    }
}