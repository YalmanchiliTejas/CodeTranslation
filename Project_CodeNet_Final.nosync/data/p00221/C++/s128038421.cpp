#include<iostream>
using namespace std;

string cast(int n){
  string ans;
  int flag = 0;
  if(n/10000){
    ans.push_back(n/10000+'0');
    n -= (n/10000)*10000;
    flag = 1;
  }
  if(n/1000 || flag == 1){
    ans.push_back(n/1000+'0');
    n -= (n/1000)*1000;
    flag = 1;
  }
  if(n/100 || flag == 1){
    ans.push_back(n/100+'0');
    n -= (n/100)*100;
    flag = 1;
  }
  if(n/10 || flag == 1){
    ans.push_back(n/10+'0');
    n -= (n/10)*10;
  }
  ans.push_back(n+'0');
  return ans;
}

int main(){
  int i,j,k;
  int m,n,r;
  char a[1000];
  string s,tmp;

  while(1){
    cin >> m >> n;
    if(!m && !n)break;

    for(i=0;i<m;i++)a[i] = '1';

    r = m;
    j = 0;
    k = 0;
    for(i=0;i<n;i++){
      cin >> s;
      if(r!=1){	
	while(a[k]!='1'){
	  k++;
	  if(k==m)k=0;
	}
	j++;
	if(j%3){
	  if(j%5){
	    tmp = cast(j);
	    if(s!=tmp){
	      a[k] = '0';
	      r--;
	    }
	  }else{
	    if(s!="Buzz"){
	      a[k] = '0';
	      r--;
	    } 
	  }
	}else{
	  if(j%5){
	    if(s!="Fizz"){
	      a[k] = '0';
	      r--;
	    } 
	  }else{
	    if(s!="FizzBuzz"){
	      a[k] = '0';
	      r--;
	    }
	  } 
	}
      }
      k++;
      if(k==m)k=0;
    }

    for(i=0;i<m;i++){
      if(a[i]=='1'){
	cout << i+1;
	r--;
	if(r!=0)cout << " ";
      }
    }
    cout << endl;
  }
}