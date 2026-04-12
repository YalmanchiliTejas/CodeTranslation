#include<iostream> //cinなど
#include<string> //文字列
#include<algorithm> //sort など
#include<math.h> //paw(冪乗など)
#include<set> // 集合
#include<map> //写像
#include<stdio.h> //printf
#include<stack>

using namespace std;
int main(){
  int N,sum,C,K;
  cin>>N;
  sum = 800 * N;
  K = N / 15;
  C = 200 * K;
  cout<< sum - C <<endl;
return 0;
}
