#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(){
  int i, count;
  string str;
  string data = "yuiophjklnm";
  string::iterator iter1, iter2;

  while(1){
    cin >> str;
    if(str == "#") break;

    iter1 = find(data.begin(), data.end(), str[0]);

    for(i=1, count=0; i<str.size(); ++i){
      iter2 = find(data.begin(), data.end(), str[i]);

      if(iter1 == data.end() && iter2 != data.end()){
	++count;
	iter1 = iter2;
      }else if(iter1 != data.end() && iter2 == data.end()){
	++count;
	iter1 = iter2;
      }
    }

    cout << count << endl;
  }
  return 0;
}