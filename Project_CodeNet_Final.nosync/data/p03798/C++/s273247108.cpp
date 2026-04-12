#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
string str;
int n;
bool func(char ch1,char ch2){
  char a[n];
  a[0] = ch1;
  a[1] = ch2;
  for(int i=0;i<n-2;i++){
    if((a[i]=='S') ^ (a[i+1] =='S') ^ (str[i+1] == 'o')){
      a[i+2] = 'S';
    }else{
      a[i+2] = 'W';
    }
  }
  //cout << (a[n-2]=='S') << (a[n-1] =='S') << (str[n-1] == 'o') << (a[0] == 'S') << endl;
  if(!((a[n-2]=='S') ^ (a[n-1] =='S') ^ (str[n-1] == 'o') ^ (a[0] == 'S'))
&& (!((a[n-1]=='S') ^ (a[0] =='S') ^ (str[0] == 'o') ^ (a[1] == 'S')))){
    for(int i=0;i<n;i++){
      cout<<a[i];
    }
    return true;
  }else{
    return false;
  }
}

int main(){
  cin >> n >> str;
  string out;
  out[0] = 'S';
  int count=0;
  if(func('S','S')||func('S','W')||func('W','S')||func('W','W')){

  }else{
    cout << -1;
  }
}
