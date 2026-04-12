#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
  map<char,int>mp;
  mp['q']=0;
  mp['w']=0;
  mp['e']=0;
  mp['r']=0;
  mp['t']=0;
  mp['a']=0;
  mp['s']=0;
  mp['d']=0;
  mp['f']=0;
  mp['g']=0;
  mp['z']=0;
  mp['x']=0;
  mp['c']=0;
  mp['v']=0;
  mp['b']=0;
  mp['y']=1;
  mp['u']=1;
  mp['i']=1;
  mp['o']=1;
  mp['p']=1;
  mp['h']=1;
  mp['j']=1;
  mp['k']=1;
  mp['l']=1;
  mp['n']=1;
  mp['m']=1;
  string s;
  while(cin>>s){
    if(s=="#"){break;}
    for(int i=0; i<s.size(); i++ ){
      if(mp[s[i]]==1){s[i]='1';}
      else {s[i]='0';}
    }
    int cnt=0;
    for(int i=0; i<s.size()-1; i++){
      if(s[i]==s[i+1]){continue;}
      if(s[i]!=s[i+1]){cnt++;}
    }
    cout<<cnt<<endl;
  }
}

  
