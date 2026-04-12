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
using namespace std;
using u8t = std::uint64_t;
using i8t = std::int64_t;
#define F(I,N) for(i8t I=0,I##_N=N;I<I##_N;I++)
#define FR(I,N) for(i8t I=N;I--;)
#define R(V) i8t V;std::cin>>V;
#define RV(V,N) std::vector<i8t> V;F(_i,N){R(_x)V.push_back(_x);}
#define RL1(line) std::getline(std::cin,line);
#define RL(line) std::string line;RL1(line)
#define RM(V,L,C) std::vector<char> V;F(_i,L){RL(_l)F(_j,C)V.push_back(_l[_j]);}
#define P(X) std::cout<<(X)<<std::endl;

template<typename T>
void print_range(T arr){
  for(auto x:arr)std::cout<<" "<<x;
  std::cout<<std::endl;
}

i8t case_even(i8t const N,std::vector<i8t>const& accum){
  i8t ans=0;
  for(int x=0;x<N;x+=2){
    i8t a1=x-1>=0?accum[x-1]:0;
    i8t a2=x-2>=0?accum[x-2]:0;
    i8t c1=a2-a1;
    ans=max(ans,c1);
  }
  ans+=accum[N-1];
  return ans;
}

int main() {
  R(N)RV(A,N);

  // N 奇数
  std::vector<i8t> accum(N+1,0);//accum[N] はダミー
  F(I,N){
    if(I==0)accum[0]=A[0];
    else if(I==1)accum[1]=A[1];
    else accum[I]=accum[I-2]+A[I];
  }

  if(N%2==0){
    i8t ans=case_even(N, accum);
    ans=max(ans,accum[N-2]);
    P(ans);
    return 0;
  }else{
    std::vector<i8t> gain(N+1,0);//gain[N]=dummy for x=N-1,
    F(x,N){
      i8t a1=x-1>=0?accum[x-1]:0;
      i8t a2=x-2>=0?accum[x-2]:0;
      i8t c1=a2-a1;
      gain[x]=c1;
    }

    // これで奇数番目は全てそれ以降の物の最大値に置き換える。
    i8t mx=gain[N-2];
    for(i8t i=N-2;i>=0;i-=2){
      gain[i]=mx=std::max(mx,gain[i]);
    }

    //print_range(gain);

    i8t ans=gain[0]+gain[1];
    for(i8t i=0;i<N-2;i+=2){
      ans=max(ans,gain[i]+gain[i+1]);
    }
    ans+=accum[N-1];
    ans=max(case_even(N-1,accum),ans);
    ans=max(ans,accum[N-3]);
    P(ans);
    return 0;

  }
  return 0;
}
