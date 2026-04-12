#include <cstdio>
#include <iostream>
#include <string>
#include <cstdlib>
#include <list>
using namespace std;
list<int> l;
int main()
{
  for(;;){
    int n,m,i;
    scanf("%d %d",&m,&n);
    if(m == 0) break;
    string dummy;
    getline(cin,dummy);
    l.clear();
    for(i=1; i<=m; i++){
      l.push_back(i);
    }
    list<int>::iterator it = l.begin();
    for(i=1; i<=n; i++){
      string s;
      getline(cin,s);
      if(l.size() == 1) continue;
      if(i % 15 == 0){
        if(s != "FizzBuzz"){
          it = l.erase(it);
        }else{
          it++;
        }
      }else if(i % 3 == 0){
        if(s != "Fizz"){
          it = l.erase(it);
        }else{
          it++;
        }
      }else if(i % 5 == 0){
        if(s != "Buzz"){
          it = l.erase(it);
        }else{
          it++;
        }
      }else{
        int j = atoi(s.c_str());
        if(j != i){
          it = l.erase(it);
        }else{
          it++;
        }
      }
      if(it == l.end()){
        it = l.begin();
      }
    }
    it = l.begin();
    printf("%d",*it);
    it++;
    for(; it != l.end(); it++){
      printf(" %d",*it);
    }
    printf("\n");
  }
  return 0;
}