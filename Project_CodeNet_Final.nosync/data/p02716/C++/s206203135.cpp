#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <string.h>
#include <string>
#include <complex>
using namespace std;
 
#define INT_max 2147483647
 
 
typedef long long ll;
typedef long double ld;
 
 
int main(){
	int n;
	cin>>n;
	if(n < 4){
		int ans;
		for(int i = 0;i < n;i++){
			int t;
			cin>>t;
			if(i == 0) ans = t;
			else ans = max(ans,t);
		}
		cout<<ans;
		return 0;
	}
	vector<ll> ans1(n,0);//记录的是当前包含i/2个数的最大和 
	vector<ll> ans2(n,0);//记录的是当前包含（i+1）/2个数的最大和
	for(int i = 0;i < n;i++){
		ll t;
		cin>>t;
		if(i < 2){
			ans2[i] = t;
		}
		else{
			if(i%2) ans2[i] = max(ans2[i-2],ans2[i-3]) + t;
			else ans2[i] = ans2[i-2]+t; 
		}
		if(i < 3){
			if(i == 2) ans1[i] = max(ans1[0],t);
			else ans1[i] = t;
		}
		else{
			if(i%2) ans1[i] = max(ans2[i-3],ans1[i-2]) + t;
			else ans1[i] = max(ans1[i-3],ans1[i-2]) + t;
		}
	}
	if(n%2) cout<<max(ans1[n-1],ans1[n-2]);
	else cout<< max(ans2[n-1],ans2[n-2]);
	return 0;
}