#include <iostream>
#include <vector>
#include<list>
#include <algorithm>
#include <string>
#include <math.h>
#include<map>
#include <utility>
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
	int N;
	cin >> N;
	int H[N];
	int max = 0;
	int count = 1;
	REP(i, N)
	{
		int h;
		cin >> h;
		if(i==0){
			max = h;
		}else{
			if(h>=max){
				count++;
				max = h;
			}
		}
	}

	cout << count << endl;

	return 0;
}