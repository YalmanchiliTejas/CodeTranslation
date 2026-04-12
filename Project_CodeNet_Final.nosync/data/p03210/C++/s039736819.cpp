#include<bits/stdc++.h>
 
using namespace std;
 
#define INF 1000000007
#define LINF 1000000000000000007
 
typedef long long ll;
typedef pair<ll,ll> P;


int x;

int main(){
	cin >> x;
	
	if(x == 3 || x == 5 || x == 7){
		cout << "YES" << endl;
	}
	else cout << "NO" << endl;
	
	return 0;
}