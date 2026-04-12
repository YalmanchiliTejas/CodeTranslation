#include <iostream>
#include <list>

using namespace std;

int main(){
     int N,M;
     while(cin>>N>>M,N||M){
	  int temp;
	  list<int> times;
	  for(int i=0;i<N+M;i++){
	       cin>>temp;
	       times.push_back(temp);
	  }
	  times.sort();
	  list<int>::iterator itr=times.begin();
	  int maxtime=0;
	  int back=0;
	  while(times.end()!=itr){
	       //cout<<*itr<<endl;
	       int d=(*itr)-back;
	       maxtime=max(maxtime,d);
	       back=(*itr);
	       itr++;
	  }
	  //cout<<endl;
	  cout<<maxtime<<endl;
     }
     return 0;
}