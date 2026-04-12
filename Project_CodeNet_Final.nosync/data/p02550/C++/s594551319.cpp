#include <iostream>
#include <vector>
using namespace std;
using ulong = unsigned long;
using ull = unsigned long long;

ulong getRepeatPos(const vector<ull> &items){
  const size_t itemSize = items.size();
  ull newestItem = items[itemSize - 1];
  for(ulong i = itemSize - 2; ; i--){
    if(newestItem == items[i]){
      return i;
    }
    if(i == 0){
      break;
    }
  }
  return itemSize;
}

ull getResult(ulong term, const uint initial, const uint mod){
  vector<ull> items(1, initial);
  ull sum = initial;
  ull newestItem = initial;

  size_t itemSize;
  ulong repeatPosMin, repeatPosMax;
  for(ulong i = 1; ; i++){
    if(i >= term){
      return sum;
    }
    items.push_back(newestItem * newestItem % mod);
    itemSize = items.size();
    newestItem = items[itemSize - 1];
	repeatPosMin = getRepeatPos(items);
	if(repeatPosMin < itemSize - 1){
      repeatPosMax = itemSize - 1;
      break;
    }
    sum += newestItem;
  }

  const ulong repeatCount = repeatPosMax - repeatPosMin;
  ull repeatSum = 0;
  for(ulong i = repeatPosMin; i < repeatPosMax; i++){
    repeatSum += items[i];
  }
  
  term -= repeatPosMax;
  sum += term / repeatCount * repeatSum;

  ulong surplus = term % repeatCount;
  if(surplus != 0){
    for(ulong i = 0; i < surplus; i++){
      sum += items[i + repeatPosMin];
    }
  }
  
  return sum;
}
 
int main(){
  ulong N;
  uint X, M;
  cin >> N >> X >> M;
  
  ull result = getResult(N, X, M);  
  cout << result;
  return 0;
}