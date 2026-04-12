#include"bits/stdc++.h"

//#include<bits/stdc++.h>
using namespace std;
#define print(x) cout<<x<<endl;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define REP(i,a) for(int i=0;i<a;i++)
typedef long long ll;
typedef pair<int, int> PI;
typedef pair<int, PI> V;
typedef vector<int> VE;
const ll mod = 100000000000;

int r, g, b;

int main() {
	cin >> r >> g >> b;
	if ((r * 100 + g * 10 + b) % 4 == 0) { print("YES"); }
	else { print("NO"); }
	return 0;
}