#include <bits/stdc++.h>
#define rep(i,a,n) for(int i = a;i < n;i++)
typedef unsigned long long ull;
typedef long long ll;
using namespace std;


ull gcd(ull a,ull b){
	if(!b) return a;
	return gcd(b,a%b);
}


int main(){
	int n,type = 0;
	cin >> n;
	int a[n];
	deque<int> b;
	
	rep(i,0,n){
		cin >> a[i];
	}
	
	rep(i,0,n){
		if(type % 2){
			b.push_back(a[i]);
		}
		else{
			b.push_front(a[i]);
		}
		type++;
	}
	
	rep(i,0,n){
		if(type % 2){
			cout << b[i];
		}
		else{
			cout << b[n-i-1];
		}
		if(i != n-1){
			cout << " ";
		}
	}
	cout << endl;
	return 0;
}