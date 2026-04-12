/* Doctor's Memorable Code */

#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
#include<cctype>

using namespace std;

string sbits(unsigned int x, int n){
  string ret;
  for(int i = 0; i < n; i++){
    ret += (x & 1) + '0';
    x >>= 1;
  }
  reverse(ret.begin(), ret.end());
  return ret;
}

string DoctorTableAD(char c){
  string ret;
  if( isupper(c) ){
    ret = sbits(c - 'A', 5);
  }else{
    const char symb[] = " .,-'\?";
    for(int i = 0; i < sizeof(symb)/sizeof(*symb); i++){
      if( c == symb[i] ){
	ret = sbits(i+26, 5);
	break;
      }
    }
  }
  return ret;
}

string DoctorTableDA(string &s){
  unsigned int pos = 0;
  string ret;
  const char ctable[] = " ',-.\?ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  const char table[][16] =
  {"101","000000","000011","10010001","010001","000001","100101","10011010","0101","0001","110","01001","10011011","010000","0111","10011000","0110","00100","10011001","10011110","00101","111","10011111","1000","00110","00111","10011100","10011101","000010","10010010","10010011","10010000"};
  
  while( true ){
    bool bFound = false;
    for(int i = 0; i < sizeof(table)/sizeof(*table); i++){
      if( 0 == s.compare(pos, strlen(table[i]), table[i]) ){
	ret += ctable[i];
	pos += strlen(table[i]);
	bFound = true;
	break;
      }
    }
    if( bFound == false ) break;
  }
  return ret;
}

string DoctorLovedDecode(string &raw){
  string s;
  for(unsigned int i = 0; i < raw.length(); i++){
    s += DoctorTableAD(raw[i]);
  }
  return DoctorTableDA( s );
}

int main(void){
  while(true){
    string s;
    
    getline(cin,s);
    if( cin.eof() ) break;
    
    cout << DoctorLovedDecode( s ) << "\n";
  }
  return 0;
}