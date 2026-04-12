#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

long long calc(long long N, long long X, vector<long long> burger_widths, vector<long long> patty_nums){
  if(N==0) return 1;
  if(X==1) return 0;
  if(X>burger_widths[N-1]+2){
    return patty_nums[N-1]+1+calc(N-1,X-burger_widths[N-1]-2,burger_widths,patty_nums);
  }else if(X==burger_widths[N-1]+2){
    return patty_nums[N-1]+1;
  }else if(X==burger_widths[N-1]+1){
    return patty_nums[N-1];
  }else{
    return calc(N-1,X-1,burger_widths,patty_nums);
  }
}
  

int main(){
  long long N,X;
  long long i;
  long long answer = 0;
  cin >> N >> X;
  long long burger_width=1;
  long long patty_num=1;
  vector<long long> burger_widths(N+1);
  vector<long long> patty_nums(N+1);
  for(i=0;i<=N;i++){
    burger_widths[i]=burger_width;
    patty_nums[i]=patty_num;
    burger_width = 2*burger_width+3;
    patty_num = 2*patty_num+1;
  }
  answer = calc(N,X,burger_widths,patty_nums);
  
  cout << answer << "\n";
}
