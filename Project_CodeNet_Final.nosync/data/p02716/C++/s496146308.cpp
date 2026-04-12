
#include <time.h>

#include <stdlib.h>
#include <cstdint>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <cstdint>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <vector>
#include <map>
#include <set>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <bitset>
#include <iterator>
#include <deque>
#include <string>
#include <queue>
#include <omp.h>
#include <fstream>   // ifstream, ofstream
typedef int64_t ll;
using namespace std;
const ll INF=1e16;
const double EPS=1e-8;
const ll mod = 1000000007;


int main(){
	ll n;
	cin>>n;
	vector<ll> a;
	for(ll i1=0;i1<n;i1++){
		ll temp;
		cin>>temp;
		a.push_back(temp);
	}
	ll *odd_sum=new ll[n];
	ll *even_sum=new ll[n];
	odd_sum[0]=0;
	even_sum[0]=a[0];
	for(ll i1=1;i1<n;i1++){
		if(i1%2==0){
			even_sum[i1]=even_sum[i1-1]+a[i1];
			odd_sum[i1]=odd_sum[i1-1];
		}else{
			even_sum[i1]=even_sum[i1-1];
			odd_sum[i1]=odd_sum[i1-1]+a[i1];
		}
	}

	if(n<=3){
		cout<<*max_element(a.begin(),a.end())<<endl;
		return 0;
	}
	if(n%2==0){
		ll ans=max(odd_sum[n-1],even_sum[n-2]);
		for(ll i1=0;i1<n-3;i1++){
			if(i1%2==0&&even_sum[i1]+odd_sum[n-1]-odd_sum[i1+2]>ans){
				ans=even_sum[i1]+odd_sum[n-1]-odd_sum[i1+2];
			}
		}
		cout<<ans<<endl;
	}else{
		//all even

		ll ans=-INF;
		for(ll i1=0;i1<n;i1++){
			if(i1%2==0){
				ll temp = even_sum[n-1]-a[i1];
				if(temp>ans){
					ans=temp;
				}
			}
		}
		ll *middle_sum=new ll[n];
		middle_sum[0]=0;
		for(ll i1=2;i1<n;i1++){
			if(i1%2==0){
				middle_sum[i1]=max(even_sum[i1-2]-odd_sum[i1],middle_sum[i1-2]);
			}
		}
		for(ll i1=2;i1<n-2;i1++){
			ll temp_ans;
			if(i1%2==1){
				temp_ans = middle_sum[i1-3]+odd_sum[i1]-even_sum[i1+2]+even_sum[n-1];
				if(temp_ans>ans){
					ans=temp_ans;
				}
			}

		}
		cout<<ans<<endl;
	}
}
