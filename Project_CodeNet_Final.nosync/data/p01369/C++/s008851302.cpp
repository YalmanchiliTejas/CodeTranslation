#include <iostream>
#include <string>

using namespace std;

bool hantei(char mozi){

  if((96<mozi && mozi<104) || (112<mozi && mozi<117) || (117<mozi && mozi!=121))
    return 1;
  else
    return 0;
}

int main(void)
{
  string typ;
  int str_size;
  bool now;
  int count;
  
  while(cin >> typ){
    count=0;

    if(typ=="#")
      return 0;
    
    str_size=typ.size();

    now=hantei(typ[0]);
    
    for(int i=1;i<str_size;i++){
      if(now!=hantei(typ[i])){
	count++;
	now=hantei(typ[i]);
      }
    }

    cout << count << endl;
  }

  return 0;
}
     
    

