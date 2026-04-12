#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long int
 
#define REP(i, n) for(int i = 0; i < (n); i++)
#define SREP(i, s) for(int i = 0; i < (s.size()); i++)
#define SORT(v, n) sort(v, v+n);
#define GSORT(v, n) sort(v, v+n, greater<int>());
#define VSORT(v) sort(v.begin(),v.end());
#define VGSORT(v) sort(v.begin(),v.end(),greater<int>());
#define REV(a) reverse(begin(a),end(a));

int main(){
	ios::sync_with_stdio(false);cin.tie(0);
////////////////////////////////////////////
	int a,b,c;
	cin >> a >> b >> c;
	cout << (a-c)/(b+c) << endl;
/////////////////////////////////////////////
}
