#include <iostream>
#include <vector>
#include<list>
#include <algorithm>
#include <string>
#include <math.h>
#include<map>
#include <utility>

#include<queue>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
 
#define INF (1e9)
typedef long long unsigned int ll;
#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))
 

template<typename T>
int vector_finder(std::vector<T> vec, T number) {
  auto itr = std::find(vec.begin(), vec.end(), number);
  size_t index = std::distance( vec.begin(), itr );
  if (index != vec.size()) { // 発見できたとき
    return 1;
  }
  else { // 発見できなかったとき
    return 0;
  }
}

int gcd(int a,int b){
	if(b>0){
		return gcd(b, a % b);
	}else{
		return a;
	}
}

int N;


int main()
{
	int A, B, C, X, Y;
	ll ans = INF;
	cin >> A >> B >> C >> X >> Y;

	REP(i,100001){
		ll cost = A * max(0,X - i) + B * max(0,Y - i) + C * 2 * i;
		if(cost<ans){
			ans = cost;
		}
	}

	cout << ans << endl;

	return 0;
}