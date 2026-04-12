#include <iostream>
#include <string>
#define Sheep 'S' 
#define Walf 'W' 
typedef char Animal;
using namespace std;

int N; 
string s;

Animal calcNextAnimal(Animal a,Animal b,int i ){
  if(a == Sheep){
    if(b == Sheep){
      if(s[i] == 'o') return Sheep;
      else return Walf;
    }else{
      if(s[i] == 'o') return Walf;
      else return Sheep;
    }
  }else{
    if(b == Sheep){
      if(s[i] == 'o') return Walf;
      else return Sheep;
    }else{
      if(s[i] == 'o') return Sheep;
      else return Walf;
    }
  }
}

int calcIndex(int i){
  if(i < N) return i;
  else return i - N;
}

bool isTrue(Animal A,Animal B){
  Animal tmpA,tmpB,tmp;
  string buf = "";
  tmpA = A;
  tmpB = B;
  buf = buf + A + B;
  for(int i=1;i<N+1;i++){
    tmp = calcNextAnimal(tmpA,tmpB,calcIndex(i));
    buf += tmp;
    tmpA = tmpB;
    tmpB = tmp;
  }
  if(buf[0] == buf[N] && buf[1] == buf[N+1]){
    cout << buf.substr(0,N) << endl;
    return true;
  }else{
    return false;
  }
}

int main(){
  cin >> N >> s;
  
  if(isTrue(Sheep,Sheep) || isTrue(Sheep,Walf) || isTrue(Walf,Sheep) || isTrue(Walf,Walf))
    return 0;
  else{
    cout << -1 << endl;
    return 0;
  }
}