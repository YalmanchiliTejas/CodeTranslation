#include <cstdio>
#include <cstdint>
#include <cinttypes>
#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <string>
using u8t = std::uint64_t;
using i8t = std::int64_t;
#define F(I,N) for(i8t I=0,_N=N;I<_N;I++)
#define FR(I,N) for(i8t I=N;I--;)
#define R(V) i8t V;std::cin>>V;
#define RV(V,N) std::vector<i8t> V;F(_i,N){R(_x)V.push_back(_x);}
#define RL1(line) std::getline(std::cin,line);
#define RL(line) std::string line;RL1(line)
#define RM(V,L,C) std::vector<char> V;F(_i,L){RL(_l)F(_j,C)V.push_back(_l[_j]);}
#define P(X) std::cout<<(X)<<std::endl;
int main() {
  R(n)RV(a,n);
  // std::vector<i8t> b;
  // F(i,n){b.push_back(a[i]);}
  // std::reverse(b.begin(),b.end());
  // F(i,n){if(i)std::cout<<" ";std::cout<<b[i];}
  // std::cout<<std::endl;
  if(n%2==0){
    F(i,n){
      if(i)std::cout<<" ";
      if(i<n/2)
        std::cout<<a[n-1-2*i];
      else
        std::cout<<a[2*(i-n/2)];
    }
  }else{
    F(i,n){
      if(i)std::cout<<" ";
      if(i<=n/2)
        std::cout<<a[n-1-2*i];
      else
        std::cout<<a[1+2*(i-n/2-1)];
    }
  }
  std::cout<<std::endl;

  return 0;
}