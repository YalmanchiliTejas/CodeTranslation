#include<bits/stdc++.h>
using namespace std;

int foo(string a){
  int i, size =  (int)a.size();
  
  for(i = 0; i < size; i++){
    if(!('0' <= a[i] && a[i] <= '9' ))return 0;
  }
  return 1;
}

int huga(int pl[], int count , int m){
  int k = 1;
  while(k <= m){
    if(count == m)count = 1;
    else count++;
    if(pl[count] != -1) return count;
    k++;
  }

  return -1;
}

int hoge(string str, int i){
  int keta = log10(i) + 1, size = (int)str.size(), an = 0, k, j = 1;


  if(keta != size)return 0;
  for(k = size - 1; k >= 0; k--){
    an += (str[k] - '0') * j;
    j *= 10;
  }  if(an == i)return 1;
  else return 0;
}


int main(){
  string str[10010];
  int m, n, temp;
  int i, j, k;

  while(1){
    int count = 1, pl [1010] ={};
    cin>>m>>n;
    if(m == 0 && n == 0) break;

    for(i = 1; i <= n; i++){
      cin>>str[i];
    }

    
    for(i = 1; i <= n; i++ ){
      if(i%5 == 0 && i%3 == 0){
	if(str[i] != "FizzBuzz"){
	  pl[count] = -1;
	}
      }else if(i%5 == 0){
	if(str[i] != "Buzz"){
	  pl[count] = -1;
	}
      } else if(i%3 == 0){
	if(str[i] != "Fizz"){
	  pl[count] = -1;

	}
      }else{

	if(foo(str[i]) == 1){
	  if(hoge(str[i], i) == 0){
	    pl[count] = -1;
	  }
	}else{
	  pl[count] = -1;

	}
      }
      
      count = huga(pl, count , m);
      
      k = 0;
      for(j = 1; j <= m; j++){
		if(pl[j] != -1)k++;
	}
      if(k == 1){
		break;
      }
      
    }

    k = 0;
    
    for(i = 1; i <= m; i++){
      if(pl[i] != -1){
	if(k) {cout<<" ";}
	cout<<i;
	k++;
      }
    }cout<<endl;
  }


  return 0;
}



