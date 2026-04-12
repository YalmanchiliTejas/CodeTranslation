#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define ll long long 
int ctoi(char c) {return c-'0';}/*char to int*/
int gcd(ll a,ll b){return b?gcd(b,a%b):a;}/*MAX*/
int lcm(ll a,ll b){return a*b/gcd(a,b);}/*MIN*/
bool primecheck(ll n){/*sosuu*/if(n < 2) return false;else{for(int i = 2; i * i <= n; i++){if(n % i == 0) return false;}return true;}}
int  main(){
	int h;
	cin >> h;
	int w;
	cin >> w;
	vector<string> a(h);
	for (int i = 0; i < h; i++) {
		cin >> a[i];
	}
 
	vector<bool> tate(h, false);
	vector<bool> yoko(w, false);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (a[i][j] == '#') {
				tate[i] = true;
				yoko[j] = true;
			}
		}
	}
 
	for (int i = 0; i < h; i++) {
		if (tate[i]) {
			for (int j = 0; j < w; j++) {
				if (yoko[j]) {
					cout << a[i][j];
				}
			}
			cout << endl;
		}
	}
}





