#include<bits/stdc++.h>
using namespace std;
//union find{
int o[100];
int u[200];
// ??¨??????????±???????
int root(int s){
  while(o[s]>=0)
    s=o[s];
  return u[s];
}

// x??¨y????±??????????????????????
void merge(int x, int y){
  x = root(x);
  y = root(y);
  if(x == y) return;
  o[x]+=o[y];
  o[y]=x;
}
// x??¨y?????????????????????true
bool same(int x,int y){
  return root(x) == root(y);
}
//}end of union find
int main(){
  string str;
  for(int i=0;i<26;i++){
    o[i+'a']=-1;
    u[i+'a']=i+'a';
  }
  merge('q','w');merge('q','e');merge('q','r');merge('q','t');merge('q','a');merge('q','s');merge('q','d');merge('q','f');merge('q','g');merge('q','z');merge('q','x');merge('q','c');merge('q','v');merge('q','b');
merge('y','u');merge('y','i');merge('y','o');merge('y','p');merge('y','h');merge('y','j');merge('y','k');merge('y','l');merge('y','n');merge('y','m');
 while(cin>>str,str!="#"){
    int ans=0;
    for(int i=0;i<str.size()-1;i++){
      if(!same(str[i],str[i+1])){
	ans++;
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}