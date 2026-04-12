#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;
const int INF = 1<<30;

int main(){
  char c;cin>>c;
  char vowel[] = {'a', 'i', 'u', 'e', 'o'};
  bool v = false;
  for(int i=0;i<5;i++){
  	if(c==vowel[i]){v=true;break;}
  }
  cout<<(v?"vowel":"consonant")<<endl;
}