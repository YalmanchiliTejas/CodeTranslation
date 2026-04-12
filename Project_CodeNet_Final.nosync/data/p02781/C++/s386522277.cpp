#include <iostream>
#include <cmath>
#include <string>

int d(std::string,int);
int BC(int,int);

int main(void){
  int K;
  std::string N;
  std::cin >> N;
  std::cin >> K;
  int ans = d(N,K);
  std::cout << ans << std::endl; 
  return 0;
}

int d(std::string  Nstr,int K){
  
  if(K==0)
    return 1;
    
  if(K!=0){
    // 桁数を求める
    int n = (int)Nstr.length();
    // n+1が桁数 n+1 < Kなら終了
    if(n < K){
      return 0;
    }
    if(n == 0){
      return 0;
    }
    // 最上位の数
    char c = Nstr[0];
    int Xn = (int)atoi(&c);
    //std::cout << Xn << std::endl;
    // あまりの数
    std::string remain = Nstr.substr(1,n);
    // 最上位が0ならremainをもって次へ
    if(Xn == 0){
      return d(remain,K);
    }
    return (Xn-1)*BC(n-1,K-1)*std::pow(9,K-1) + BC(n-1,K)*std::pow(9,K) + d(remain,K-1);
  }else{
    return 0;
  }
  return 0;
}

int BC(int n, int k) {
  if(n < k)
    return 0;
   if (k == 0 || k == n){
   	  return 1;
   }
   return BC(n - 1, k - 1) + BC(n - 1, k);
}
