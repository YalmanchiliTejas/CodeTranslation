#include <vector>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <math.h>
#include <list>

using namespace std;

int sum_digit(int n) {
	if (n == 0) return 0;
	else return n % 10 + sum_digit(n / 10);
}
int absolute(int a) {
	if (a < 0) return -a;
	else return a;
}
void uniq(list<int> &lst) {
	auto itr = lst.begin();
	if (itr == lst.end()) return;
	int prev = *itr++;
	while(itr != lst.end()) {
		if (*itr == prev) {
			itr = lst.erase(itr);
		}
		else {
			prev = *itr++;
		}
	}
}
int main()
{
  int N; cin >> N;
  vector<int> H(N); for(int i = 0;i < N;i++) cin >> H.at(i);
  
  int count = 0;
  int localmax;
  for(int i = 0;i < N; i++){
    if(i == 0){
      count++;
      localmax = H.at(0);
    }else if(localmax <= H.at(i)){
      count++;
      localmax = H.at(i);
    }
  }
  
  cout << count << endl;
}