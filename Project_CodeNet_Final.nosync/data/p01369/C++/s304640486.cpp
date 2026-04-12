#include <iostream>
#include <string>

using namespace std;

int main()
{
  string str, key = "qwertasdfgzxcvb";

  while(cin>>str && str != "#"){
    int cnt = 0, hand = 2;

    for(int i = 0; i < str.size(); i++){
      bool f = true;
      for(int j = 0; j < key.size(); j++){
	if(str[i] == key[j]){
	  f = false;
	  break;
	}
      }

      if(f && hand != 1){
	hand = 1;
	cnt++;
      } else if(!f && hand != 0){
	hand = 0;
	cnt++;
      }
    }
    cnt--;

    cout << cnt << endl;
  }


  return 0;
}