#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N=0;
  vector<int> szamok;
  int seged=0;
  cin>>N;
  for(int i=0;i<N;i++){
    cin >>seged;
    szamok.push_back(seged);
  }
  bool vane=true;
  seged=1;
  for(int i=1; i<N;i++){
     for(int j=0; j<i; j++){
       if(szamok[j]>szamok[i]){
         vane=false;
         break;
       }
     }
       if(vane){
         seged++;
       }
       vane=true;
  }
  
  cout<<seged;
	return 0;
}
