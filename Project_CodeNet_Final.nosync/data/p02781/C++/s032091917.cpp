#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
static const ll MOD = 1000000007;

int judge(string x, string y){
  if(x.size() > y.size()){
    return 1;
  }else if(x.size() < y.size()){
    return -1;
  }else{
    for(int i = 0; i < x.size(); i++){
      if(x[i] > y[i]){
	return 1;
      }else if(x[i] < y[i]){
	return -1;
      }else{
	continue;
      }
    }
    return 0;
  }
}

int main(){
  string N;
  int K;
  cin >> N >> K;
  ll len = N.size();
  int top = N[0] - '0';
  ll res = 0;
  if(K == 1){
    res += (len - 1) * 9;
    res += top;
  }
  if(K == 2){
    for(int i = 1; i < len-1; i++){
      res += 9 * 9 * i;
    }
    for(int i = 1; i < len; i++){
      for(int j = 1; j < 10; j++){
	for(int k = 1; k < 10; k++){
	  string tmp(len, '0');
	  tmp[0] = j + '0';
	  tmp[i] = k + '0';
	  if(judge(N, tmp) >= 0){
	    res++;
	  }
	}
      }
    }
  }
  if(K == 3){
    for(int i = 2; i < len - 1; i++){
      res += 9 * 9 * 9 * (i * (i-1)) / 2;
    }
    for(int i = 1; i < len; i++){
      for(int j = i + 1; j < len; j++){
	for(int a = 1; a < 10; a++){
	  for(int b = 1; b < 10; b++){
	    for(int c = 1; c < 10; c++){
	      string tmp(len, '0');
	      tmp[0] = a + '0';
	      tmp[i] = b + '0';
	      tmp[j] = c + '0';
	      if(judge(N, tmp) >= 0){
		res++;
	      }
	    }
	  }
	}
      }
    }
  }
  cout << res << endl;
}
