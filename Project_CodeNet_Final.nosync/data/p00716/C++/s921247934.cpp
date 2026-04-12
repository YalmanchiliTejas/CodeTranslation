#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <ctype.h>
#include <ctime>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <numeric>
#include <complex>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

#define REP(i, x, n) for(int i = x; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define lengthof(x) (sizeof(x) / sizeof(*(x)))
#define FILL(ptr, value) FILL_((ptr), sizeof(ptr)/sizeof(value), (value))
template <typename T>
void FILL_(void * ptr, size_t size, T value){
  std::fill((T*)ptr, (T*)ptr+size, value);
}
//4方向ベクトル→↑←↓
int dx[] ={1,0,-1,0};
int dy[] ={0,-1,0,1};

int main()
{
  int n;
  scanf("%d",&n);
  double sisan;//初期運用資金
  int nensu;//運用年数
  int k;//種類
  int l;//単離か福利
  double riritu,tesuu;
  int ans = 0;
  for(int i = 0;i < n;i++){
    cin >>sisan>>nensu>>k;
    int ans1=0;
    int ans2=0;
    for(int j = 0;j < k;j++){
      int tanans=0;
      int hukuans=0;
      
      cin >>l>>riritu>>tesuu;
      if(l ==0){
	tanans = sisan;
	int sum =0;//利子累計
	for(int m = 0; m <nensu ;m++){
	  sum +=tanans*riritu;
	  tanans -=tesuu;
	}
	tanans +=sum;
	ans1 =max(ans1,tanans);
      }else{
	hukuans = sisan;
	for(int m = 0;m <nensu;m++){
	  hukuans +=(hukuans)*riritu-tesuu;
	}
	ans2 = max(ans2,hukuans);
      }
      ans = max(ans1,ans2);
    }
    cout <<ans<<endl;
  }
  return 0;
}