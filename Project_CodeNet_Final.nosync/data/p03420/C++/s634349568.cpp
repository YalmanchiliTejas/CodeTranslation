#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#define _USE_MATH_DEFINES
#include <cmath>
#include <numeric>
#include <iomanip>
#include <deque>
#include <tuple>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <sstream>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>

#define rep(i, x) for (int i = 0; i < (int)(x); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define F first
#define S second
#define pb push_back
#define pf push_front

namespace mp = boost::multiprecision;
using cpp_int = mp::cpp_int;
using ll = long long;
using namespace std;

ll M = 1000000007;

int main()
{
	int n,k;
	cin>>n>>k;
	ll cnt=0;
	FOR(i,k+1,n+1){
		int tmp=i;
		int dis=tmp-k;
		while(1){
			if(tmp<=n){
				cnt+=dis;
			}else if(tmp-dis<=n){
				cnt+=n-(tmp-dis)+1;
				if(k==0){
					cnt--;
				}
			}
			else{
				break;
			}
			tmp+=i;
		}
	}
	cout<<cnt<<endl;
}
