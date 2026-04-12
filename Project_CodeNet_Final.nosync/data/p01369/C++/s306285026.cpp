#include<iostream>
using namespace std;
string a="qwertasdfgzxcvb";
main(){
  string in;while(cin>>in && in != "#"){
    int ans=-1,now=-1;
    for(int i=0;i<in.size();i++){
      int next=1;
      for(int j=0;j<a.size();j++)if (a[j] == in[i]){next=0;break;}
      if (now != next)ans++;
      now=next;
    }
    cout << ans << endl;
  }
}