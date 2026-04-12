#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
const int mod=1e9+7;
using LL=long long;
using std::cout;using std::endl;using std::cin;
using std::vector;using std::string;using std::set;using std::multiset;
using std::pair;using std::map;
using std::min;using std::max;
using std::make_pair;
std::ostream& operator<<(std::ostream& os,std::map<int,int>& obj){for(std::map<int,int>::iterator itr=obj.begin();itr!=obj.end();itr++){os<<itr->first<<"^"<<itr->second<<" ";}return os;}
std::ostream& operator<<(std::ostream& os,std::vector<std::map<int,int>>& obj){for(auto itr=obj.begin();itr!=obj.end();itr++){os<<*itr<<std::endl;}return os;}
std::ostream& operator<<(std::ostream& os,std::vector<int>& obj){for(auto itr=obj.begin();itr!=obj.end();itr++){os<<*itr<<endl;}return os;}

namespace ndifix{
template<class T>void sort(T &v){std::sort(v.begin(),v.end());}
}

int main(){
  int x;cin>>x;
  if(x==3||x==5||x==7)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  return 0;
}