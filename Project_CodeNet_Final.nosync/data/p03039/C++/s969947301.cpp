#include <iostream>
#include <vector>

#define llint long long int

#define MAX 200001
#define NUM 1000000007

#define MULT(x,y) ( ((x)%NUM)*((y)%NUM) %NUM)
#define ADD(x,y)  ((((x)%NUM)+((y)%NUM))%NUM)

std::vector<llint>  fac(MAX);
std::vector<llint> finv(MAX);

llint pow(llint base, llint exp){
  llint res = 1;
  while(exp > 1){
    if(exp%2){
      res = MULT(res, base);
    }
    base = MULT(base, base);
    exp/=2;
  }
  return MULT(res, base);
}

void comb_init(){
  fac[0] = 1;
  for(int i=1; i<MAX; i++){
    fac[i] = MULT(fac[i-1], i);
  }
  finv[MAX-1] = pow(fac[MAX-1], NUM-2);
  for(int i=MAX-2; i>=0; i--){
    finv[i] = MULT(finv[i+1], i+1);
  }
}

llint comb(llint a, llint b){
  return MULT(MULT(fac[a], finv[a-b]), finv[b]);
}

int main(void){
  llint n, m, k;
  std::cin >> n >> m >> k;

  comb_init();

  llint total = 0;
  for(int d=1; d<n; d++){
    total = ADD(total, MULT(d*(n-d)*m*m, comb(n*m-2, k-2)));
  }

  for(int d=1; d<m; d++){
    total = ADD(total, MULT(d*(m-d)*n*n, comb(n*m-2, k-2)));
  }
  std::cout << total << std::endl;
  
  return 0;
}
