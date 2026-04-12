#include<bits/stdc++.h>
using namespace std;



int main(){
  set<char> r;
  r.insert('q');
  r.insert('w');
  r.insert('e');
  r.insert('r');
  r.insert('t');
  r.insert('a');
  r.insert('s');
  r.insert('d');
  r.insert('f');
  r.insert('g');
  r.insert('z');
  r.insert('x');
  r.insert('c');
  r.insert('v');
  r.insert('b');


  while(1){
  int count=0;
  char w='l';
  string s;
  getline(cin,s);
  if(s=="#"){break;}
  if(r.find(s[0])!=r.end()){w='r';}
  for(int i=1;i<s.size();i++){
    if(r.find(s[i])!=r.end() && w=='l'){w='r'; count++; continue;}
    if(r.find(s[i])==r.end() && w=='r'){w='l'; count++;}
  }
  cout<<count<<endl;
  }
  return 0;
}

