#include<bits/stdc++.h>
using namespace std;
const int ms = 1e5+9;
int vet[ms];
int main(){
	int maxi = 0, n,soma =1,s=1;
 	cin >> n;
  	for(int i =0 ;i<n;i++) cin >> vet[i];
  for(int i = 1;i<n;i++){
  	if(vet[i] >= vet[i-1])
      	s++;
   	vet[i] = max(vet[i],vet[i-1]);
  }
  cout<<s<<endl;
}