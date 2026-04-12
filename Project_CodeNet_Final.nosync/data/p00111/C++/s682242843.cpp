#include <iostream>
#include <map>

using namespace std;

int main(void){
  string s;
  map<char,string> table1;
  map<string,char> table2;
  for(char c='A';c<='Z';++c){
    int a = c-'A';
    for(int j=0;j<5;++j){
      table1[c] = ((a%2)?'1':'0')+table1[c];
      a/=2;
    }
  }
  table1[' ']="11010";
  table1['.']="11011";
  table1[',']="11100";
  table1['-']="11101";
  table1['\'']="11110";
  table1['?']="11111";
  
  table2["101"]=' ';
  table2["000000"]='\'';
  table2["000011"]=',';
  table2["10010001"]='-';
  table2["010001"]='.';
  table2["000001"]='?';
  table2["100101"]='A';
  table2["10011010"]='B';
  table2["0101"]='C';
  table2["0001"]='D';
  table2["110"]='E';
  table2["01001"]='F';
  table2["10011011"]='G';
  table2["010000"]='H';
  table2["0111"]='I';
  table2["10011000"]='J';
  table2["0110"]='K';
  table2["00100"]='L';
  table2["10011001"]='M';
  table2["10011110"]='N';
  table2["00101"]='O';
  table2["111"]='P';
  table2["10011111"]='Q';
  table2["1000"]='R';
  table2["00110"]='S';
  table2["00111"]='T';
  table2["10011100"]='U';
  table2["10011101"]='V';
  table2["000010"]='W';
  table2["10010010"]='X';
  table2["10010011"]='Y';
  table2["10010000"]='Z';
  
  while(getline(cin,s),!cin.eof()){
    string decoded,result;
    for(int i=0;i<s.size();++i){
      decoded+=table1[s[i]];
    }
    string tmp;
    //cerr<<decoded<<endl;
    for(int i=0;i<decoded.size();++i){
      tmp += decoded[i];
      if(table2.find(tmp) != table2.end()){
        result+=table2[tmp];
        tmp="";
      }
    }
    cout<<result<<endl;
  }
  return 0;
}