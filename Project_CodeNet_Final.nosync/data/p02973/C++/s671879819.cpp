#include <iostream>
#include <cstring>
#include <string>    
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll n, a[100008];
string str;

int main(){
	cin >> n;
	for(ll i = 1; i <= n; i++){cin >> a[i];}
	
	vector<ll> c;
	c.push_back(a[n]);
	ll amax = a[n];
	
	for(ll i = n-1; i >= 1; i--){
		if(a[i] >= amax){
			c.push_back(a[i]);
			amax = a[i];
		}
		else{
			ll lng = -1;
			ll rok = c.size()-1;
			while(rok-lng > 1){
				ll buf = (lng+rok)/2;
				if(a[i] < c[buf]){rok = buf;}
				else{lng = buf;}
			}
			//while(rok > 1 && c[rok] == c[rok-1]){rok--;}
			c[rok] = a[i];
			if(rok == c.size()-1){amax = a[i];}
		}
	}
	
	cout << c.size() << endl;
	return 0;
}