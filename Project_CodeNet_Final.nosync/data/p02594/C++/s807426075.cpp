#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const long long MAX = 2000000;

template <typename T> T gcd(T a, T b) { return b != 0 ? gcd(b, a % b) : a; }

template <typename T> T lcm(T a, T b) { return a * b / gcd(a, b); }



int main() {
	int N;
	cin>>N;
	if(N>=30){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}


}
