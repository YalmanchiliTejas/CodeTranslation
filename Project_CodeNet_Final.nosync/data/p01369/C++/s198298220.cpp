#include <iostream>
using namespace std;

int main(){
  char buf[40];
  int kld[]={1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1,1,1,0,1};
  int bi,wasleftk,kccnt;

  while (1){
    cin >> buf;
    if (buf[0]=='#')break;
    bi=0;
    wasleftk=2;
    kccnt=-1;
    while (buf[bi]!='\0'){
      if (kld[buf[bi]-'a']!=wasleftk){
	kccnt++;
	wasleftk=kld[buf[bi]-'a'];
      }
      bi++;
    }
    cout << kccnt << endl;
  }
  return 0;
}