#include <stdio.h>

int main(void){
  int m;
  unsigned long long int money;
  int year;
  int n;
  int fukuri;
  double nenri;
  unsigned long long int risi;
  unsigned int tesu;
  unsigned long long int tempmoney;
  unsigned long long int maxmoney;
  
  scanf("%d", &m);
  for(int i=0; i<m; i++){
    scanf("%lli", &money);
    scanf("%d", &year);
    scanf("%d", &n);
    maxmoney = money;
    for(int j=0; j<n; j++){
      tempmoney = money;
      risi = 0;
      scanf("%d%lf%d", &fukuri, &nenri, &tesu);
      if(fukuri){
	for(int y=0; y<year; y++){
	  tempmoney += (tempmoney*nenri-tesu);
	}
      }else{
	for(int y=0; y<year; y++){
	  risi += tempmoney*nenri;
	  tempmoney -= tesu;
	}
	tempmoney += risi;
      }
      if(tempmoney > maxmoney){
	maxmoney = tempmoney;
      }
    }
    printf("%lli\n", maxmoney);
  }
  return 0;
}