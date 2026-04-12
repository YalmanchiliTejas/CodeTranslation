#include<iostream>
#include<string>

using namespace std;

int main(){

  string N;
  int a=0,b=0,t;

  while(cin>>N){

    if(N=="#"){
      break;
    }


  for(int i=0;i<N.size();i++){


      if(N[i]=='q'||N[i]=='w'||N[i]=='e'||N[i]=='r'||N[i]=='t'||N[i]=='a'||N[i]=='s'||N[i]=='d'||N[i]=='f'||N[i]=='g'||N[i]=='z'||N[i]=='x'||N[i]=='c'||N[i]=='v'||N[i]=='b'){
      if(N[i+1]=='y'||N[i+1]=='u'||N[i+1]=='i'||N[i+1]=='o'||N[i+1]=='p'||N[i+1]=='h'||N[i+1]=='j'||N[i+1]=='k'||N[i+1]=='l'||N[i+1]=='n'||N[i+1]=='m'){
      b=b+1;
    }
    }else if(N[i]=='y'||N[i]=='u'||N[i]=='i'||N[i]=='o'||N[i]=='p'||N[i]=='h'||N[i]=='j'||N[i]=='k'||N[i]=='l'||N[i]=='n'||N[i]=='m'){
     if(N[i+1]=='q'||N[i+1]=='w'||N[i+1]=='e'||N[i+1]=='r'||N[i+1]=='t'||N[i+1]=='a'||N[i+1]=='s'||N[i+1]=='d'||N[i+1]=='f'||N[i+1]=='g'||N[i+1]=='z'||N[i+1]=='x'||N[i+1]=='c'||N[i+1]=='v'||N[i+1]=='b'){
       b=b+1;
    }
    }
  }
  cout<<b<<endl;

  b=0;

  }

  return 0;
}