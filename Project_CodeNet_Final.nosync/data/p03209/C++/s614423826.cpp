#include<bits/stdc++.h>
#include<math.h>
#include <stdio.h>
#include<vector>
#include <iostream>
//#include <algorithm>
#include <limits>
#include<string>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
using namespace std;
#define llMAX numeric_limits<long long>::max()
#define intMAX numeric_limits<int>::max()
#define ll long long
ll XOR(ll a,ll b){
  ll result=0;
  while(1){
    if(a%2==b%2){
      result+=0;
    }else{
      result+=1;
    }
    a/=2;
    b/=2;
    if(a==0&&b==0){
      return result;;
    }
    result*=2;
  }
}
string printbinary(ll num){
  string result = "";
  while(num!=0){
    if(num%2==0){
      result =result + "0";
    }else{
      result =result + "1";
    }
    num/=2;
  }
  return result;
}
ll p(int n){
  return (ll)pow(2,n+1)-1;
}
ll x(int n){
  return (ll)pow(2,n+2)-3;
}
ll search(int n,ll num){//再帰
  if(n==0){
    return 1;
  }else if(num==1){
    return 0;
  }
  if(num==x(n)){
    return p(n);
  }
  if(num<=(x(n)-1)/2){//左側
    return search(n-1,num-1);//一番左のバンに注意
  }else if(num==(x(n)+1)/2){
    return (p(n)-1)/2 +1;
  }else{
    return ((p(n)+1)/2) + search(n-1,num-(x(n)+1)/2);
  }
}
int main(void){
	int N;
	cin >> N;
  ll X;
  cin >> X;
  //x_n = 2^(n+2) -3
  //p_n=2^(n+1) -1
  cout << search(N,X);
	return 0;
}