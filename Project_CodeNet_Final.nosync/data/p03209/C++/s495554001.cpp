#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <climits>
#include <bitset>
#include <list>
#include <map>
#include <set>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

ll burger[51];

void set_burger(int n){
	burger[0]=1;
	for(int i=1; i<=n; i++){
		burger[i]=2*burger[i-1]+3;
	}
	return;
}

ll eat(ll n, ll k){
	if(n==0) return 1;
	if(k==1) return 0;
	else if(k<=1+burger[n-1]) return eat(n-1, k-1);
	else if(k==2+burger[n-1]) return eat(n-1, k-1)+1;
	else if(k<=2+2*burger[n-1]) return 1+eat(n-1, burger[n-1])+eat(n-1, k-burger[n-1]-2);
	else return 2*eat(n-1, burger[n-1])+1;
}

int main(){
	int n;
	ll x;
	cin >> n >> x;
	set_burger(n);
	cout << eat(n, x) << endl;
	return 0;
}