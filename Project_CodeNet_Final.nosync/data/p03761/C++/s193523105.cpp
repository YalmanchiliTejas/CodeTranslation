#include <iostream>
#include <map>
using namespace std;

int main(int argc, char *argv[]){
  int N;
  cin>>N;
  map<char,int> mp;
  for(int i=0; i<N; i++){
    string S;
    cin>>S;
    if(i==0){
      for(int j=0; j<S.size(); j++){
	mp[S[j]]++;
      }
    }
    else{
       map<char,int> cntmp;
      for(int j=0; j<S.size(); j++){
	cntmp[S[j]]++;
      }
      for(auto itr=mp.begin(); itr!=mp.end(); itr++){
	if(cntmp.count(itr->first)){
	  if(cntmp[itr->first]<=itr->second) mp[itr->first]=cntmp[itr->first];
	}
	else mp.erase(itr);
      }
    }
  }
  for(auto itr=mp.begin(); itr!=mp.end(); itr++){
    for(int i=0; i<itr->second; i++){
      cout<<itr->first;
    }
  }
}

