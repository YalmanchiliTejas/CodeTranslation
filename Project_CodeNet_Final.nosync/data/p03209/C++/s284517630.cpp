#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int N;
  unsigned long X;
  long pnum = 0;
  unsigned long index;
  
  cin >> N >> X;
  vector<unsigned long> p(N+1);
  vector<unsigned long> s(N+1);
  p[0] = 1;
  s[0] = 1;
  for(int i = 1; i <= N; i++){
    p[i] = 1 + 2*p[i-1];
    s[i] = 3 + 2*s[i-1];
  }
  index =  X;
  int i;
  for(i = N; i > 0; i--){
    if(index == 1){
      break;
    }
    else if(index == 2+s[i-1]){
      pnum += p[i-1]+1;
      break;
    }
    else if(index == 3+2*s[i-1]){
      pnum += 2*p[i-1]+1;
      break;
    }
    else if(index < 2+s[i-1]){
      index -= 1;
      if(i == 1){
      	pnum++;
      	break;
      }
      continue;
    }
    else if(index < 3 + 2*s[i-1]){
      if(i == 1){
        pnum += 3;
        break;
      }
      pnum += 1+p[i-1];
      index -= 2+s[i-1];
      continue;
    }
  }
    cout << pnum << endl;
}