#include <cstdio>
#include <cstdint>
#include <cinttypes>
#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
#include <numeric>

using u4t = std::uint32_t;
using i4t = std::int32_t;
using u8t = std::uint64_t;
using i8t = std::int64_t;

int main() {
  int N;
  std::cin>>N;
  int _min_min=1e9;
  int _min_max=1e9;
  int _max_min=0;
  int _max_max=0;
  int _minminc_min=1e9;
  int _minminc_max=0;
  int _maxmaxc_min=1e9;
  int _maxmaxc_max=0;
  std::vector<int> xx,yy;
  for(int i=0;i<N;i++){
    int x,y;
    std::cin>>x>>y;
    if(x>y)std::swap(x,y);
    xx.push_back(x);
    yy.push_back(y);
    int ominmin=_min_min,omaxmax=_max_max;
    _min_min=std::min(_min_min,x);
    _min_max=std::min(_min_max,y);
    _max_min=std::max(_max_min,x);
    _max_max=std::max(_max_max,y);
    if(_min_min!=ominmin){_minminc_min=1e9;_minminc_max=0;}
    if(_max_max!=omaxmax){_maxmaxc_min=1e9;_maxmaxc_max=0;}
    if(_min_min==x){
      _minminc_max=std::max(_minminc_max,y);
      _minminc_min=std::min(_minminc_min,y);
    }
    if(_max_max==y){
      _maxmaxc_max=std::max(_maxmaxc_max,x);
      _maxmaxc_min=std::min(_maxmaxc_min,x);
    }
  }
  int _min_max2=1e9;
  int _max_min2=0;
  for(int i=0;i<N;i++){
    int x=xx[i],y=yy[i];
    if(_min_min!=x&&_max_max!=y){
      _min_max2=std::min(_min_max2,y);
      _max_min2=std::max(_max_min2,x);
    }
  }
  int _max_comp=std::max({_maxmaxc_max,_minminc_max,_max_min2});
  int _min_comp=std::min({_maxmaxc_min,_minminc_min,_min_max2});
  for(int i=0;i<N;i++){
    int x=xx[i],y=yy[i];
    if(_min_comp<=x&&x<=_max_comp||_min_comp<=y&&y<=_max_comp)continue;
    int xdist=x<_min_comp?_min_comp-x:x-_max_comp;
    int ydist=y<_min_comp?_min_comp-y:y-_max_comp;
    int xy=xdist<ydist?x:y;
    _max_comp=std::max(_max_comp,xy);
    _min_comp=std::min(_min_comp,xy);
  }


  i8t ans = std::min(
    (i8t)(_max_max-_min_min)*(_max_comp-_min_comp),
    (i8t)(_max_max-_min_max)*(_max_min-_min_min));
  std::cout << ans<<std::endl;
  return 0;
}
