#include <iostream>
#include <deque>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;


int main(){
  long long N,a,ab,af,sb,sf;
  deque<int> A,S;
  multimap<int,string> list;
  cin >> N;
  for(int i=0;i<N;i++){
    cin >> a;
    A.push_back(a);
  }
  sort(A.begin(),A.end());
  S.push_back(A.back());
  A.pop_back();
  long long ans=0;
  while(!A.empty()){
    list.clear();
    ab=A.back();
    af=A.front();
    sb=S.back();
    sf=S.front();
    list.emplace(abs(ab-sb),"back_back");
    list.emplace(abs(ab-sf),"back_front");
    list.emplace(abs(af-sb),"front_back");
    list.emplace(abs(af-sf),"front_front");
    auto itr = list.rbegin();
    ans += itr->first;
    if(itr->second=="back_back"){
      A.pop_back();
      S.push_back(ab);
    }else if(itr->second=="back_front"){
      A.pop_back();
      S.push_front(ab);
    }else if(itr->second=="front_back"){
      A.pop_front();
      S.push_back(af);
    }else if(itr->second=="front_front"){
      A.pop_front();
      S.push_front(af);
    }else{
      cout << "ouch" <<endl;
    }
  }
  cout << ans << endl;
}
  