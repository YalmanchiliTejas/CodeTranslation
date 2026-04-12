#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
using namespace std;

#define INF 1000000007

int main(){
  long long int N = 0,count = 0;
  cin >> N;
  vector<long long int> box(N);
  for(int i = 0;i < N;i++){
    cin >> box.at(i);
    count += box.at(i);
    count = count % INF;
  }
  //cout << count << endl;
  long long int answer = 0,now = 0;
  for(int i = 0;i < N - 1;i++){
    //cout << box.at(i) << endl;
    count = count - box.at(i);
    if(count < 0){
      count += INF;
    }
    now = box.at(i)*count;
    //cout << a << " " << now << endl;
    answer += now;
    answer = answer % INF;
  }
  cout << answer << endl;
}
