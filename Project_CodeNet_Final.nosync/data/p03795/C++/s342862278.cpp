#include<bits/stdc++.h>
 
#define INF 1000000007
#define LINF 1000000000000000007
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> P;


int n;

int main(){
	cin >> n;
	
	cout << n*800 - 200*(n/15) << endl;
	
	return 0;
}