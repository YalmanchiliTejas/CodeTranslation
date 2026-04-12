#include <bits/stdc++.h>
using namespace std;
vector<int>v;
string s;
int ary[100005] = {0};
int main(){
  int flag;

  char l_list[] = {'q','w','e','r','t','a','s','d','f','g','z','x','c','v','b'};
  char r_list[] = {'y','u','i','o','p','h','j','k','l','n','m'};
  cin >>s;
  while(s != "#"){
    int ans = 0;

    for(int i = 0;i<15;i++){
      if(s[0] ==  l_list[i]){
        flag = 1;
      }
    }
    for(int i = 0;i<11;i++){
      if(s[0] == r_list[i]){
        flag = 0;
      }
    }

    for(int j = 1;j < (int)s.size();j++){
      int now_flag = flag;
      for(int i = 0;i<15;i++){
        if(s[j] ==  l_list[i]){
          flag = 1;
        }
      }
      for(int i = 0;i<11;i++){
        if(s[j] == r_list[i]){
          flag = 0;
        }
      }
      if(flag != now_flag){
        ans++;
      }
    }
    v.push_back(ans);
    cin >>s;
  }

  for (int i = 0;i<(int)v.size();i++){
    cout <<v[i]<<endl;
  }
  return 0;
}

