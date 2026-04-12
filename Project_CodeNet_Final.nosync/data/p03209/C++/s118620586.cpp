#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
#define ll long long
void file(){
#ifndef ONLINE_JUDGE
	freopen("a_input.txt", "r", stdin);
	freopen("a_output.txt", "w", stdout);
#endif
}
void fast()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
}
ll p[55], a[55];
void build(int n){
	if (n > 50)return;
	p[n] = 2 * p[n - 1] + 1;
	a[n] = 2 * a[n - 1] + 3;
	build(n + 1);
}
ll get(int n, ll x){
	if (n == 0)return x > 0;
	if (x <= a[n - 1] + 1)
		return get(n - 1, x - 1);
	return p[n - 1] + 1 + get(n - 1, x - 2 - a[n - 1]);
}
int main(){
	//file();
	fast();
	p[0] = 1;
	a[0] = 1;
	build(1);
	ll n, x;
	cin >> n>> x;
	cout << get(n, x) << endl;
}
