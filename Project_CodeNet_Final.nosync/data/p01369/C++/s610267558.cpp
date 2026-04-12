#include<iostream>
#include<string>

using namespace std;

int main(){
  while(1){

    int le=0,ri=0,count=0;
    string str;
    cin>>str;
    if(str[0]=='#') break;
  
    for(int i=0;i<str.size();i++){
      if(i==0){
	if (str[i]=='q' || str[i]=='w' || str[i]=='e' || str[i]=='r' ||
	    str[i]=='t' || str[i]=='a' || str[i]=='s' || str[i]=='d' ||
	    str[i]=='f' || str[i]=='g' || str[i]=='z' || str[i]=='x' ||
	    str[i]=='c' || str[i]=='v' || str[i]=='b') le=1;
	else ri=1;
      }
      if(i>0){
	if(ri==1 &&( str[i]=='q' || str[i]=='w' || str[i]=='e' || str[i]=='r' ||
		     str[i]=='t' || str[i]=='a' || str[i]=='s' || str[i]=='d' ||
		     str[i]=='f' || str[i]=='g' || str[i]=='z' || str[i]=='x' ||
		     str[i]=='c' || str[i]=='v' || str[i]=='b')){
	  count++;
	  le=1;
	  ri=0;
	}
	else if(le==1 && (str[i]=='y' || str[i]=='u' || str[i]=='i' || str[i]=='o' ||
			  str[i]=='p' || str[i]=='h' || str[i]=='j' || str[i]=='k' ||
			  str[i]=='l' || str[i]=='n' || str[i]=='m')){
	  count++;
	  ri=1;
	  le=0;
	}
      }
    }
    cout<<count<<endl;
  }
  return 0;
}
  