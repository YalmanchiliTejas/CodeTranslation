#include <iostream>
#include <map>
#include <string>

using namespace std;

main(){
  map<char,string> data1;
  map<string,char> data2;
  map<string,bool> data3;
  data1['A']="00000";
  data1['B']="00001";
  data1['C']="00010";
  data1['D']="00011";
  data1['E']="00100";
  data1['F']="00101";
  data1['G']="00110";
  data1['H']="00111";
  data1['I']="01000";
  data1['J']="01001";
  data1['K']="01010";
  data1['L']="01011";
  data1['M']="01100";
  data1['N']="01101";
  data1['O']="01110";
  data1['P']="01111";
  data1['Q']="10000";
  data1['R']="10001";
  data1['S']="10010";
  data1['T']="10011";
  data1['U']="10100";
  data1['V']="10101";
  data1['W']="10110";
  data1['X']="10111";
  data1['Y']="11000";
  data1['Z']="11001";
  data1[' ']="11010";
  data1['.']="11011";
  data1[',']="11100";
  data1['-']="11101";
  data1['\'']="11110";
  data1['?']="11111";

  data2["101"]=' ';
  data2["000000"]='\'';
  data2["000011"]=',';
  data2["10010001"]='-';
  data2["010001"]='.';
  data2["000001"]='?';
  data2["100101"]='A';
  data2["10011010"]='B';
  data2["0101"]='C';
  data2["0001"]='D';
  data2["110"]='E';
  data2["01001"]='F';
  data2["10011011"]='G';
  data2["010000"]='H';
  data2["0111"]='I';
  data2["10011000"]='J';
  data2["0110"]='K';
  data2["00100"]='L';
  data2["10011001"]='M';
  data2["10011110"]='N';
  data2["00101"]='O';
  data2["111"]='P';
  data2["10011111"]='Q';
  data2["1000"]='R';
  data2["00110"]='S';
  data2["00111"]='T';
  data2["10011100"]='U';
  data2["10011101"]='V';
  data2["000010"]='W';
  data2["10010010"]='X';
  data2["10010011"]='Y';
  data2["10010000"]='Z';

  data3["101"]=true;
  data3["000000"]=true;
  data3["000011"]=true;
  data3["10010001"]=true;
  data3["010001"]=true;
  data3["000001"]=true;
  data3["100101"]=true;
  data3["10011010"]=true;
  data3["0101"]=true;
  data3["0001"]=true;
  data3["110"]=true;
  data3["01001"]=true;
  data3["10011011"]=true;
  data3["010000"]=true;
  data3["0111"]=true;
  data3["10011000"]=true;
  data3["0110"]=true;
  data3["00100"]=true;
  data3["10011001"]=true;
  data3["10011110"]=true;
  data3["00101"]=true;
  data3["111"]=true;
  data3["10011111"]=true;
  data3["1000"]=true;
  data3["00110"]=true;
  data3["00111"]=true;
  data3["10011100"]=true;
  data3["10011101"]=true;
  data3["000010"]=true;
  data3["10010010"]=true;
  data3["10010011"]=true;
  data3["10010000"]=true;

  char c;
  while(1){
    if(scanf("%c", &c)==EOF) break;
    string in="";
    while(1){
      if(c=='\n') break;
      in+=c;
      scanf("%c", &c);
    }
    string tmp1="";
    for(int i=0;i<in.size();i++){
      tmp1+=data1[in[i]];
    }
    string tmp2="";
    string ans="";
    for(int i=0;i<tmp1.size();i++){
      tmp2+=tmp1[i];
      if(data3[tmp2]){
	ans+=data2[tmp2];
	tmp2="";
      }
    }
    cout << ans << endl;
  }
  return 0;
}