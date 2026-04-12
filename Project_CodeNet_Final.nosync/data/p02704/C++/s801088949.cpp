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
using vi8t = std::vector<i8t>;
using vu8t = std::vector<u8t>;
#define F3(i,i0,iN,step) for(i8t i=i0,i##_N=iN;i<i##_N;i+=step)
#define F2(i,i0,iN) F3(i,i0,iN,1)
#define F(i,N) F3(i,0,N,1)
#define FR(I,N) for(i8t I=N;I--;)
#define R(V) u8t V;std::cin>>V;
#define RV(V,N) std::vector<u8t> V;F(_i,N){R(_x)V.push_back(_x);}
#define RL1(line) std::getline(std::cin,line);
#define RL(line) std::string line;RL1(line)
#define RM(V,L,C) std::vector<char> V;F(_i,L){RL(_l)F(_j,C)V.push_back(_l[_j]);}
#define P(X) std::cout<<(X)<<std::endl;

int arr_compare(vu8t const& a, vu8t const& b) {
  F(i,std::min(a.size(), b.size())){
    if (a[i] < b[i]) return -1;
    else if(a[i]>b[i]) return 1;
  }
  if (a.size() < b.size()) return 1;
  if (a.size() > b.size()) return 1;
  return 0;
}
template<typename T>
void arr_print(T arr){
  int i=0;
  for(auto x:arr){if(i++)std::cout<<" ";std::cout<<x;}
  std::cout<<std::endl;
}

#include <random>
u8t debug_rand(){
  static std::mt19937 engine(12345);
  static std::uniform_int_distribution<u8t> dist(0, (u8t) -1);
  return dist(engine);
}

template<typename T>
void arr_print2d(std::vector<T> const& arr, u8t N){
  F(x,arr.size()/N){
    F(y,N){
      std::cout<<arr[x*N+y];
      std::cout<<(y+1==N?"\n":" ");
    }
  }
  std::cout<<std::flush;
}

//-----------------------------------------------------------------------------

vu8t solve1(u8t N,vu8t const& S,vu8t const& T,vu8t const& U,vu8t const& V){
  vu8t result(N*N,0);

  vi8t mat;
  for(int i=0;i<64;i++){
    u8t bit = (u8t)1<<i;
    mat.clear();
    mat.resize(N*N,2); // 2 不確定状態

    // 確定部分は確定させる
    F(x,N){
      int s=S[x];
      int u=U[x]&bit?1:0;
      int t=T[x];
      int v=V[x]&bit?1:0;
      if (s!=u){
        F(y,N){
          if(mat[x*N+y]==1-u)goto No;
          mat[x*N+y]=u;
        }
      }
      if (t!=v){
        F(y,N){
          if(mat[y*N+x]==1-v)goto No;
          mat[y*N+x]=v;
        }
      }
    }

    //不確定部分で "どれか一つ" の要求が未充足の物
    vi8t s_solve_x[2];
    vi8t t_solve_x[2];
    while (1) {
      int propagate=0;
      s_solve_x[0].clear();
      s_solve_x[1].clear();
      t_solve_x[0].clear();
      t_solve_x[1].clear();
      F(x,N){
        int s=S[x];
        int u=U[x]&bit?1:0;
        int t=T[x];
        int v=V[x]&bit?1:0;
        if (s==u){
          bool found=false;
          F(y,N)if(mat[x*N+y]==u){found=true;break;}
          if(!found){
            s_solve_x[u].push_back(x);
          }else{
            F(y,N)if(mat[x*N+y]==2){mat[x*N+y]=T[y];propagate++;}
          }
        }
        if (t==v){
          bool found=false;
          F(y,N)if(mat[y*N+x]==v){found=true;break;}
          if(!found){
            t_solve_x[v].push_back(x);
          }else{
            F(y,N)if(mat[y*N+x]==2){mat[y*N+x]=S[y];propagate++;}
          }
        }
      }
      if(propagate==0)break;
    }

    auto s_has = s_solve_x[0].size()+s_solve_x[1].size();
    auto t_has = t_solve_x[0].size()+t_solve_x[1].size();
    if(s_has||t_has){
      if(!s_has||!t_has){
        // 一方だけが未確定の場合には駄目
        goto No;
      }else if(s_solve_x[0].size()&&s_solve_x[1].size()){
        // s0 s1 両方ある時
        for(auto x:s_solve_x[0])
          F(y,N)if(mat[x*N+y]==2)mat[x*N+y]=S[x];
        for(auto x:s_solve_x[1])
          F(y,N)if(mat[x*N+y]==2)mat[x*N+y]=S[x];
      }else if(t_solve_x[0].size()&&t_solve_x[1].size()){
        // t0 t1 両方ある時
        for(auto x:t_solve_x[0])
          F(y,N)if(mat[y*N+x]==2)mat[y*N+x]=T[x];
        for(auto x:t_solve_x[1])
          F(y,N)if(mat[y*N+x]==2)mat[y*N+x]=T[x];
      }else if(t_solve_x[0].size()&&s_solve_x[0].size()){
        // t0 と s0 がある時(他はない)
        for(auto x:s_solve_x[0])
          F(y,N)if(mat[x*N+y]==2)mat[x*N+y]=0;
        for(auto x:t_solve_x[0])
          F(y,N)if(mat[y*N+x]==2)mat[y*N+x]=0;
      }else if(t_solve_x[1].size()&&s_solve_x[1].size()){
        // t1 と s1 がある時(他はない)
        for(auto x:s_solve_x[1])
          F(y,N)if(mat[x*N+y]==2)mat[x*N+y]=1;
        for(auto x:t_solve_x[1])
          F(y,N)if(mat[y*N+x]==2)mat[y*N+x]=1;
      }else if(s_has>=2&&t_has>=2){
        std::vector<i8t> ss=s_solve_x[0];
        for(auto x:s_solve_x[1])ss.push_back(x);
        std::vector<i8t> tt=t_solve_x[0];
        for(auto x:t_solve_x[1])tt.push_back(x);

        u8t rev = (s_has>t_has) == (s_solve_x[0].size()!=0) ? 0:1;

        for(int i=0;i<ss.size();i++){
          for(int j=0;j<tt.size();j++) {
            auto const x = ss[i];
            auto const y = tt[j];
            mat[x*N+y]= (i==j?1:0)^rev;
          }
        }
      }else{
        goto No;
      }
    }

    F(I,N*N){
      if(mat[I]&1)result[I]|=bit;
    }
  }

  return result;
No:
  result.clear();
  return result;
}

void debug_calcUV(u8t n, vu8t const& arr, vu8t const& S, vu8t const& T, vu8t& U, vu8t& V){
  U.resize(n);
  F(x,n){
    if(S[x]){
      U[x]=0;
      F(y,n)U[x]|=arr[x*n+y];
    }else{
      U[x]=-1;
      F(y,n)U[x]&=arr[x*n+y];
    }
  }
  V.resize(n);
  F(y,n){
    if(T[y]){
      V[y]=0;
      F(x,n)V[y]|=arr[x*n+y];
    }else{
      V[y]=-1;
      F(x,n)V[y]&=arr[x*n+y];
    }
  }
}

void debug1(){
  using namespace std;
  F2(n,1,5)F(t,10000){
    vu8t S(n);
    vu8t T(n);
    generate(S.begin(), S.end(), []{return debug_rand()&1;});
    generate(T.begin(), T.end(), []{return debug_rand()&1;});

    vu8t ans(n*n);
    generate(ans.begin(),ans.end(),[]{return debug_rand()&1;});
    //generate(ans.begin(),ans.end(),debug_rand);
    vu8t U0,V0;
    debug_calcUV(n,ans,S,T,U0,V0);

    vu8t res = solve1(n,S,T,U0,V0);
    if (res.empty()){
      cerr<<"failed to solve"<<endl;
      arr_print(U0);
      arr_print(V0);
      return;
    }

    vu8t U1,V1;
    debug_calcUV(n,res,S,T,U1,V1);
    if (arr_compare(U0, U1) || arr_compare(V0, V1)){
      cerr << "fail" << endl;
      cerr<< "S "; arr_print(S);
      cerr<< "T "; arr_print(T);
      cerr<< "U "; arr_print(U0);
      cerr<< "V "; arr_print(V0);
      std::cout<<std::endl;

      arr_print2d(res,n);
      cerr<< "U "; arr_print(U1);
      cerr<< "V "; arr_print(V1);
      return;
    }
  }
}

int main() {
  //debug1();return 0;

  R(N);
  RV(S,N);
  RV(T,N);
  RV(U,N);
  RV(V,N);

  auto result = solve1(N,S,T,U,V);
  if (result.empty()){
    P(-1);
    return 0;
  }

  arr_print2d(result,N);

  return 0;
}
