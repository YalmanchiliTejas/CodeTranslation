#include <bits/stdc++.h>

#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ff first
#define ss second
#define pi 3.14159265

using namespace std;
#define prime 1000000007

const ll N = 300005;

#define W(x) cerr << "\033[31m" << #x << " = " << x << "\033[0m" << "\n";

int k, n, m;
string s;

using namespace std;

int ce(int a, int b){
	return (a+b-1)/b;
}

int main(){
	cin >> n >> s >> k;

	for (int i = 0; i < n; ++i){
		if(s[i] != s[k-1])printf("*");
		else printf("%c", s[i]);
	}
	printf("\n");

	
	return 0;
}