#include <iostream>
using namespace std;

int main(){
  char l[33];

  while((cin>>l)&&(l[0]!='#')){
    int count=0;
    int size=0;
    for(int i=0;i<33;i++){
      if(l[i]=='\0'){
        size = i;
        break;
      }
    }
    int hand=-1;
    for(int i=0;i<size;i++){
      if(l[i]=='y'||l[i]=='u'||l[i]=='i'||l[i]=='o'||l[i]=='p'||l[i]=='h'||l[i]=='j'||l[i]=='k'||l[i]=='l'||l[i]=='n'||l[i]=='m'){
        if(hand==-1) hand=0;
        if(hand==1){
          hand=0;
          count++;
        }
      }else if(l[i]=='q'||l[i]=='w'||l[i]=='e'||l[i]=='r'||l[i]=='t'||l[i]=='a'||l[i]=='s'||l[i]=='d'||l[i]=='f'||l[i]=='g'||l[i]=='z'||l[i]=='x'||l[i]=='c'||
          l[i]=='v'||l[i]=='b'){
        if(hand==-1) hand=1;
        if(hand==0){
          hand=1;
          count++;
        }
      }
    }
    cout << count << endl;
  }

  return 0;
}