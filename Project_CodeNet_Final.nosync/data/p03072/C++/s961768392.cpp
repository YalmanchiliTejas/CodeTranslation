#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,m=0,ryokan=0;
  cin>>N;

  vector<int> vec(N);
  for(int i=0;i<N;i++)
  	cin>>vec.at(i);

  for(int i=0;i<N;i++){
  	if(m <= vec.at(i)){
  		ryokan++;
  		m=vec.at(i);
  	}
  }

  cout<<ryokan<<endl;
  
}
