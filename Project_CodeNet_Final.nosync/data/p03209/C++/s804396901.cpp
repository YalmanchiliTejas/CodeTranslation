#include<iostream>
using namespace std;
typedef long long ll;
ll bag_p[51],pat_p[51];
ll calc(ll lv,ll x){
//  cout << lv<<" "<<x<<" "<<bag_p[lv]<<endl;
  if(lv==0){
    return 1;
  }
  lv--;
  if(x==1){
    return 0;
  }else if(x<=bag_p[lv]+1){
    return calc(lv,x-1);
  }else if(x==bag_p[lv]+2){
    return pat_p[lv]+1;
  }else if(x<=bag_p[lv]*2+2){
    return pat_p[lv]+1+calc(lv,x-(bag_p[lv]+2));
  }else{
    return 1+pat_p[lv]*2;
  }
}
int main(){
  ll n,x,p_sum=1,b_sum=1,lv;
  cin >> n>>x;
  bag_p[0]=pat_p[0]=1;
  for(int i=1;i<=n;i++){
    p_sum = p_sum*2+1;
    b_sum = b_sum*2+3;
    pat_p[i]=p_sum;
    bag_p[i]=b_sum;
  }
  lv=n;
  cout << calc(lv,x)<<endl;
}
