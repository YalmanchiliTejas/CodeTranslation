#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

int main() {
  
  int a,b;
  char buf[10];
  char* p;
  
  fgets(buf,sizeof(buf),stdin);

  buf[strlen(buf)-1]='\0';

  p=strtok(buf," ");
  a=atoi(p);
  p=strtok(NULL," ");
  b=atoi(p);

  if(a<b) cout << "a < b\n";
  else if(a>b) cout << "a > b\n";
  else cout << "a == b\n";

  return 0;
}