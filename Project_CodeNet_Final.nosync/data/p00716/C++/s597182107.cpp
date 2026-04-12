#include<iostream>
using namespace std;
int main()
{
  int m,fund,years,n;
  int sort;
  double interest;
  int charge;
  int max,money,stock,i;
  cin>>m;
  while(m-->0){
    cin>>fund>>years>>n;
    max=0;
    while(n-->0){
      cin>>sort>>interest>>charge;
      money=fund;
      stock=0;
      for(i=0;i<years;i++){
	stock+=(int)((double)money*interest);
	if(sort==1){money+=stock;stock=0;}
	money-=charge;
      }
      if(max<money+stock)max=money+stock;
    }
    cout<<max<<endl;
  }
}