#include <bits/stdc++.h>
#define REP(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define REPR(i, n) for(int (i) = (n); (i) >= 0; (i)--)
#define FOR(i, m, n) for(int (i) = (m); (i) < (n); (i)++)
#define INF 1e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

bool compare_by_b(pair<int, int> a, pair<int, int> b) {
    if(a.second != b.second){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}

int main()
{	
	int n, m;
	cin >> n >> m;
    if(n == m) cout << "Yes" << endl;
    else cout << "No" << endl;
}
