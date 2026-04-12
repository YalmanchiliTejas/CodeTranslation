#include<iostream>
using namespace std;
int main(){
  string a;
  while(true){
    cin >> a;
    if(a == "#")
      break;
    int count=0;
    int s[26]={0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,1,0,0,0,1,0};
    for(int i=0;i<a.size()-1;i++){
      if(s[a[i]-'a']!=s[a[i+1]-'a'])
        count++;
    }
    cout << count << endl;
  }
}