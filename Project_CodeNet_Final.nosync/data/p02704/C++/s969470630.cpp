#include <bits/stdc++.h>

#define fst(t) std::get<0>(t)
#define snd(t) std::get<1>(t)
#define thd(t) std::get<2>(t)
#define unless(p) if(!(p))
#define until(p) while(!(p))

using ull = std::uint64_t;
using ll = std::int64_t;
using P = std::tuple<int,int>;

constexpr int AND = 0;
constexpr int OR = 1;

int N;
int S[500], T[500];
ull U[500], V[500];
ull A[500][500];

bool check(int x){
    for(int i=0;i<N;++i){
        if(S[i] == AND){
            ull acc = -1;

            for(int j=0;j<N;++j){
                acc &= A[i][j];
            }

            if((acc >> x & 1) != (U[i] >> x & 1)){
                return false;
            }
        }else{
            ull acc = 0;
          
            for(int j=0;j<N;++j){
                acc |= A[i][j];
            }

            if((acc >> x & 1) != (U[i] >> x & 1)){
                return false;
            }
        }
    }

    for(int i=0;i<N;++i){
        if(T[i] == AND){
            ull acc = -1;

            for(int j=0;j<N;++j){
                acc &= A[j][i];
            }

            if((acc >> x & 1) != (V[i] >> x & 1)){
                return false;
            }
        }else{
            ull acc = 0;
          
            for(int j=0;j<N;++j){
                acc |= A[j][i];
            }

            if((acc >> x & 1) != (V[i] >> x & 1)){
                return false;
            }
        }
    }

    return true;
}

int main(){
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  std::cin >> N;

  for(int i=0;i<N;++i){
      std::cin >> S[i];
  }

  for(int i=0;i<N;++i){
      std::cin >> T[i];
  }

  for(int i=0;i<N;++i){
      std::cin >> U[i];
  }  

  for(int i=0;i<N;++i){
      std::cin >> V[i];
  }

  for(int i=0;i<64;++i){
      std::vector<int> and_0_rows, or_1_rows, and_0_cols, or_1_cols;
      std::vector<bool> check_r(500, false), check_c(500, false);

      for(int j=0;j<N;++j){
          if(S[j] == AND){
              if((U[j] >> i & 1) == 1){
                  for(int k=0;k<N;++k){
                      A[j][k] |= 1ull << i;
                      if(T[k] == OR && (V[k] >> i & 1) == 1){
                          check_c[k] = true;
                      }
                  }
              }else{
                  and_0_rows.emplace_back(j);
              }
          }else{
              if((U[j] >> i & 1) == 0){
                  for(int k=0;k<N;++k){
                      A[j][k] &= ~(1ull << i);
                      if(T[k] == AND && (V[k] >> i & 1) == 0){
                          check_c[k] = true;
                      }
                  }
              }else{
                  or_1_rows.emplace_back(j);
              }
          }
      }

      for(int j=0;j<N;++j){
          if(T[j] == AND){
              if((V[j] >> i & 1) == 1){
                  for(int k=0;k<N;++k){
                      A[k][j] |= 1ull << i;
                      if(S[k] == OR && (U[k] >> i & 1) == 1){
                          check_r[k] = true;
                      }
                  }
              }else{
                  and_0_cols.emplace_back(j);
              }
          }else{
              if((V[j] >> i & 1) == 0){
                  for(int k=0;k<N;++k){
                      A[k][j] &= ~(1ull << i);
                      if(S[k] == AND && (U[k] >> i & 1) == 0){
                          check_r[k] = true;
                      }
                  }
              }else{
                  or_1_cols.emplace_back(j);
              }
          }
      }      

      if(and_0_rows.size() > 0 && or_1_rows.size() > 0){
          for(int j : and_0_rows){
              for(int k : and_0_cols){
                  A[j][k] &= ~(1ull << i);
              }

              for(int k : or_1_cols){
                  A[j][k] &= ~(1ull << i);
              }
          }

          for(int j : or_1_rows){
              for(int k : and_0_cols){
                  A[j][k] |= 1ull << i;
              }

              for(int k : or_1_cols){
                  A[j][k] |= 1ull << i;
              }
          }
      }else if(and_0_cols.size() > 0 && or_1_cols.size() > 0){
          for(int j : and_0_cols){
              for(int k : and_0_rows){
                  A[k][j] &= ~(1ull << i);
              }

              for(int k : or_1_rows){
                  A[k][j] &= ~(1ull << i);
              }
          }

          for(int j : or_1_cols){
              for(int k : and_0_rows){
                  A[k][j] |= 1ull << i;
              }

              for(int k : or_1_rows){
                  A[k][j] |= 1ull << i;
              }
          }          
      }else if(and_0_rows.size() > 0 && and_0_cols.size() > 0){
          for(int j : and_0_rows){
              for(int k : and_0_cols){
                  A[j][k] &= ~(1ull << i);
              }
          }
      }else if(or_1_rows.size() > 0 && or_1_cols.size() > 0){
          for(int j : or_1_rows){
              for(int k : or_1_cols){
                  A[j][k] |= 1ull << i;
              }
          }
      }else{
          auto rows(std::move(and_0_rows));
          auto cols(std::move(and_0_cols));
          std::move(or_1_rows.begin(), or_1_rows.end(), std::back_inserter(rows));
          std::move(or_1_cols.begin(), or_1_cols.end(), std::back_inserter(cols));

          if(rows.empty() || cols.empty()){
              // do nothing
          }else if(rows.size() == 1 || cols.size() == 1){
              int r1 = rows[0], c1 = cols[0];

              for(int j : rows){
                  if(check_r[j]){
                      r1 = j;
                  }
              }

              for(int j : cols){
                  if(check_c[j]){
                      c1 = j;
                  }
              }
              
              for(int j : rows){
                  for(int k : cols){
                      A[j][k] &= ~(1ull << i);
                  }
              }

              A[r1][c1] |= 1ull << i;

              unless(check(i)){
                  for(int j : rows){
                      for(int k : cols){
                          A[j][k] |= 1ull << i;
                      }
                  }

                  A[r1][c1] &= ~(1ull << i);                  
              }
          }else{
              for(int j=0;j<rows.size();++j){
                  for(int k=0;k<cols.size();++k){
                      if((j + k) & 1){
                          A[rows[j]][cols[k]] |= 1ull << i;
                      }else{
                          A[rows[j]][cols[k]] &= ~(1ull << i);
                      }
                  }
              }
          }
      }
  }

  bool ok = true;

  for(int i=0;i<64;++i){
      unless(check(i)){
          ok = false;
      }
  }

  if(ok){
      for(int i=0;i<N;++i){
          for(int j=0;j<N;++j){
              std::cout << A[i][j] << " \n"[j+1==N];
          }
      }
  }else{
      std::cout << -1 << std::endl;
  }
}
