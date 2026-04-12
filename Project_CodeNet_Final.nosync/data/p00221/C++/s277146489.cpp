#include<iostream>
#include<vector>
#include<sstream>
using namespace std;
int m,n,pos;
string str;
vector<int> t;

bool check(int x){
  if(x%15==0)return (str=="FizzBuzz");
  if(x%5==0)return (str=="Buzz");
  if(x%3==0)return (str=="Fizz");
  if('0'<=str[0]&&str[0]<='9'){
    stringstream ss;
    ss<<str;
    int num;
    ss>>num;
    return (num==x);
  }else return false;
}

int main(){
  while(cin>>m>>n&&m&&n){
    t.clear();
    for(int i=0;i<m;i++)t.push_back(i+1);
    pos=0;
    for(int i=1;i<=n;i++){
      cin>>str;
      if(t.size()==1)continue;
      if(!check(i)){
	t.erase(t.begin()+pos);
	pos--;
      }
      pos++;
      if(pos==(int)t.size())pos=0;
    }
    for(int i=0;i<(int)t.size();i++){
      if(i)cout<<' ';
      cout<<t[i];
    }
    cout<<endl;
  }
  return 0;
}