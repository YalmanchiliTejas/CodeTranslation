#include<iostream>
#include<stack>
using namespace std;
string s;
int n;
int p;

int getNum(){
  int res=0;
  while('0'<=s[p]&&s[p]<='9'){
    res*=10;
    res+=(s[p]-'0');
    p++;
  }
  return res;
}

int calc(){
  stack<int> st;
  st.push(getNum());
  while(1){
    char ch=s[p++];
    if(ch=='=')break;
    int num=getNum();
    if(ch=='+')st.push(num);
    else if(ch=='*'){
      int x=st.top();st.pop();
      st.push(x*num);
    }
  }
  int res=0;
  while(!st.empty()){
    res+=st.top();
    st.pop();
  }
  return res;
}

int calc2(){
  int res=getNum();
  while(1){
    char ch=s[p++];
    if(ch=='=')break;
    int num=getNum();
    if(ch=='+')res+=num;
    else if(ch=='*')res*=num;
  }
  return res;
}

int main(){
  cin>>s>>n;
  s+="=";
  p=0;
  int a=calc();
  p=0;
  int b=calc2();
  if(a==n&&b!=n)cout<<'M'<<endl;
  else if(a!=n&&b==n)cout<<'L'<<endl;
  else if(a==n&&b==n)cout<<'U'<<endl;
  else cout<<'I'<<endl;
  return 0;
}