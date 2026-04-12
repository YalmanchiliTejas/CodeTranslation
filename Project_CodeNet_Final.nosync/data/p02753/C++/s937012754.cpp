#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <functional>
#include <numeric>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <limits>
#include <iomanip>
#include <bitset>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <stdio.h>

#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define INPUT1(n, a) for(int i##n = 0; i##n < n; i##n++) {cin >> a[i##n]; } //n = count, a = vector 
#define OUTPUT1(n, a) cout << "---count---" << endl << n << endl << "---content---" << endl; for(const auto b : a){cout << b << endl; }
#define INPUT2(x, y, field) for(int i##x = 0; i##x < y; i##x++) { for(int j##x = 0; j##x < x; j##x++) { cin >> field[i##x][j##x]; } }
#define OUTPUT2(x, y, field) cout << "---count---" << endl << x << " " << y << endl <<"---content---" << endl; for(int i##x = 0; i##x < y; i##x++) { cout << i##x << "   "; for(int j##x = 0; j##x < x; j##x++) { cout << field[i##x][j##x] << " "; } cout << endl; }

using namespace std;
using ll = long long;

const int INF = 1001001001;

int main()
{
	char x, y;
	cin>>x;
	
	rep(i, 2){
	    cin>>y;
	    
	    if(x!=y){
	        cout<<"Yes";
	        return 0;
	    }
	}
	
	cout<<"No";
}