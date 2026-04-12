
#include <iostream>
#include <vector>
#include <set>
using namespace std;
const string r = "qwertasdfgzxcvb";//1
const string l = "yuiophjklnm";//0
int main(){
  //  cout << l.size();
  string tmp;
  while(cin >> tmp,tmp != "#"){
    int cnt = 0;
    int flag = 0;
    set<char> l_s;
    for(int i =0;i < l.size();i++){
      l_s.insert(l[i]);
    }
    if(l_s.find(tmp[0]) == l_s.end()){
      flag = 1;
    }else{
      flag = 0;
    }
    for(int i = 1;i < tmp.size();i++){
      if(l_s.find(tmp[i]) == l_s.end()){
	if(flag == 0){
	  cnt++;
	}
	flag = 1;
      }else{
	if(flag == 1)cnt++;
	flag = 0;
      }
    }
    cout << cnt << endl;
  }
}