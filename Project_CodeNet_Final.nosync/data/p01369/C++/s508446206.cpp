#include<bits/stdc++.h>
using namespace std;

int main(){
  string str;
  while(cin >> str,str[0]!='#'){
    int sum=0;
    int frg=0;
    for(auto i: str){
      switch(i){
      case 'y' : if(frg!=1)++sum;frg=1;break;
      case 'u' : if(frg!=1)++sum;frg=1;break;
      case 'i' : if(frg!=1)++sum;frg=1;break;
      case 'o' : if(frg!=1)++sum;frg=1;break;
      case 'p' : if(frg!=1)++sum;frg=1;break;
      case 'h' : if(frg!=1)++sum;frg=1;break;
      case 'j' : if(frg!=1)++sum;frg=1;break;
      case 'k' : if(frg!=1)++sum;frg=1;break;
      case 'l' : if(frg!=1)++sum;frg=1;break;
      case 'n' : if(frg!=1)++sum;frg=1;break;
      case 'm' : if(frg!=1)++sum;frg=1;break;
      default  : if(frg!=2)++sum;frg=2;break;
      }
    }
    cout << sum-1 << endl;
  }
}

