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
 

 
int vector_finder(std::vector<int> vec, int number) {
  size_t index = std::distance( vec.begin(), std::find(vec.begin(), vec.end(), number) );
  if (index != vec.size()) { // 発見できたとき
    return 1;
  }
  else { // 発見できなかったとき
    return 0;
  }
}


int main()
{
	int N, K;
	string S;
	cin >> N >> S >> K;

	int s = S[K];

	REP(i,N){
		if(S[i]!=S[K-1]){
			S[i] = '*';
		}
	}

	cout << S << endl;

	return 0;
}