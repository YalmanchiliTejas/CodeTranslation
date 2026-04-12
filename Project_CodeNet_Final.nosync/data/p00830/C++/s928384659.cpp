#include<bits/stdc++.h>
using namespace std;
int N,M;
string s;
map< vector<string> , bool > isD,isF;

vector<string> change(string s,bool flg=true){
  
  for(int i=0;i<(int)s.size();i++)
    if(s[i]=='/')s[i]=' ';
  
  vector<string> res;
  stringstream ss(s);
  string tmp;
  while(ss>>tmp){
    if(flg)isD[res]=true;
    res.push_back(tmp);
  }
  return res;
}

vector<string> solve(string s){
  vector<string> res,vec;
  vector<string> err(10,"?");
  
  vec=change(s,false);

  for(int i=0;i<(int)vec.size();i++){
    if(vec[i]=="."){
      if(!isD[res])return err;
      continue;
    }else if(vec[i]==".."){
      if(!isD[res])return err;
      if(res.empty())return err;
      res.pop_back();
    }else{
      res.push_back(vec[i]);
      if(!isF[res]&&!isD[res])return err;
    }
  }
  if(isD[res])res.push_back("index.html");
  else if(isF[res]&&s[s.size()-1]=='/')return err;
  return res;
}

void init(){
  isD.clear();
  isF.clear();
}

void printv(vector<string> A){
  for(int i=0;i<(int)A.size();i++)
    cout<<A[i]<<' ';
  cout<<endl;
}

int main(){
  while(1){
    cin>>N>>M;
    if(N==0&&M==0)break;
    init();
    for(int i=0;i<N;i++){
      cin>>s;s="root"+s;
      vector<string> A=change(s);
      isF[A]=true;
    }

    
    for(int i=0;i<M;i++){
      cin>>s;s="root"+s;
      vector<string> A=solve(s);
      cin>>s;s="root"+s;
      vector<string> B=solve(s);
      //cout<<endl;
      //printv(A);
      //printv(B);
      if(!isF[A]){
	cout<<"not found"<<endl;
      }else if(!isF[B]){
	cout<<"not found"<<endl;
      }else if(A==B){
	cout<<"yes"<<endl;
      }else{
	cout<<"no"<<endl;
      }
    }
    
  }
  return 0;
}