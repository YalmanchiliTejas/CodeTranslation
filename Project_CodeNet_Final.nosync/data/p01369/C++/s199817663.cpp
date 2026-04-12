#include<iostream>
using namespace std;
string a="qwertasdfgzxcvb";
main(){
  string b;while(cin>>b&&b!="#"){
    int c=-1,d=-1;
    for(int i=0;i<b.size();i++){
      int e=1;
      for(int j=0;j<a.size();j++)if(a[j]==b[i])e=0;
      if (d!=e)c++;
      d=e;
    }
    cout<<c<<endl;
  }
}