#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstring>
#include <sstream>
#include <cassert>
using namespace std;
static const double EPS = 1e-5;
typedef long long ll;
typedef pair<int,int> PI;
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define mp make_pair
#define pb push_back


map<string,char> dic;

string encode(char c){
  if(isalpha(c))c-='A';
  else{
    switch(c){
    case ' ':c=26;break;
    case '.':c=27;break;
    case ',':c=28;break;
    case '-':c=29;break;
    case '\'':c=30;break;
    case '?':c=31;break;
    }
  }
  
  string ret;
  while(c){
    ret+='0'+c%2;
    c/=2;
  }
  while(ret.size()<5)ret+='0';
  reverse(ret.begin(),ret.end());
  return ret;
}

main(){
  dic["101"]=' ';
  dic["000000"]='\'';
  dic["000011"]=',';
  dic["10010001"]='-';
  dic["010001"]='.';
  dic["000001"]='?';
  dic["100101"]='A';
  dic["10011010"]='B';
	
  dic["0101"]='C';
  dic["0001"]='D';
  dic["110"]='E';
  dic["01001"]='F';
  dic["10011011"]='G';
  dic["010000"]='H';
  dic["0111"]='I';
  dic["10011000"]='J';
	
  dic["0110"]='K';
  dic["00100"]='L';
  dic["10011001"]='M';
  dic["10011110"]='N';
  dic["00101"]='O';
  dic["111"]='P';
  dic["10011111"]='Q';
  dic["1000"]='R';
	
  dic["00110"]='S';
  dic["00111"]='T';
  dic["10011100"]='U';
  dic["10011101"]='V';
  dic["000010"]='W';
  dic["10010010"]='X';
  dic["10010011"]='Y';
  dic["10010000"]='Z';
  string str;

  while(getline(cin,str)){
    string code;
    rep(i,str.size()){
      if(str[i]=='\n' || str[i]=='\r')continue;
      code+=encode(str[i]);
      //cout<<code<<endl;
    }
    int i=0;
    string dec;
    while(i<code.size()){
      dec+=code[i];
      ++i;
      if(dic.count(dec)){
        cout<<dic[dec];
        dec="";
      }
    }
    cout<<endl;
  }
}