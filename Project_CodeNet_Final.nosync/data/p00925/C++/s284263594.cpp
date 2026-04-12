#include <iostream>
#include <string>
using namespace std;

int comM(string str){
  int res = 0,sum = 0;
  if(str[1] == '+' || str.size() == 1) res = str[0]-'0';
  for(int i=0;i<str.size();i++) {
    if(str[i] =='*' && sum == 0) sum += (str[i-1]-'0') * (str[i+1]-'0');
    else if(str[i] =='*' && sum != 0) sum *= (str[i+1] - '0');
    else if(str[i] == '+') res += sum,sum = 0;
    if(str[i] == '+' && (i+1 == str.size()-1||str[i+2] != '*')) res += str[i+1]-'0';
  }
  return res+sum;
} 

int comL(string str) {
  int res = str[0]-'0';
  for(int i=0;i<str.size();i++)
    if(str[i] == '*') res *= (str[i+1]-'0');
    else if(str[i]=='+') res += (str[i+1]-'0');
  return res;
}

int main(){
  string str;
  cin >> str;
  int n;
  cin >> n;
  int M = comM(str);
  int L = comL(str);
  if(M==n && L == n) cout << "U"<<endl;
  else if(M==n) cout << "M"<<endl;
  else if(L==n) cout <<"L"<<endl;
  else cout << "I"<<endl;
  return 0;
}