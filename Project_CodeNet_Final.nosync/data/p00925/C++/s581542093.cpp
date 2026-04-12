#include <bits/stdc++.h>

using namespace std;

int l_r_rule(string s){
  int len=s.length();
  int res=0;
  char ope='+';
  for(int i=0;i<len;i++){
    if(i%2==0){//??°???
      if(ope=='+') res+=(s[i]-48);
      else res*=(s[i]-48);
    }
    else ope=s[i];
  }
  return res;
}

int m_f_rule(string s){
  s+='+';
  int len=s.length();
  std::vector<int> v;
  int tmp=-1;
  for(int i=0;i<len/2;i++){
    if(s[i*2+1]=='+'){
      if(tmp==-1) v.push_back((s[i*2]-48));
      else v.push_back(tmp);
      tmp=-1;
    }
    else{
      if(tmp==-1) tmp=(s[i*2]-48);
      //cout <<tmp<<endl;
      tmp*=(s[i*2+2]-48);
      //cout <<tmp<<endl;
    }
  }
  int vlen=v.size();
  int res=0;
  for(int i=0;i<vlen;i++) res+=v[i];
  return res;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s;int n;
  cin>>s>>n;
  int mans=m_f_rule(s);
  int lans=l_r_rule(s);
  // cout << mans<<" "<<lans<<endl;
  if(mans==n&&lans==n) cout <<"U"<<endl;
  else if(mans==n) cout <<"M"<<endl;
  else if(lans==n) cout << "L"<<endl;
  else cout <<"I"<<endl;
}