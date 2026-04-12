#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<queue>
#include<algorithm>
#include<cmath>
#define INF 2147483647
#define llINF 9223372036854775807
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long

using namespace std;
int main(){
  string str;
  cin>>str;
  int flag=0;
  for(int i=0;i<str.size()-1;i++){
    if(str[i]=='A'&&str[i+1]=='C'){
      flag=1;
      break;
    }
  }
  if(flag)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
  return 0;
}
