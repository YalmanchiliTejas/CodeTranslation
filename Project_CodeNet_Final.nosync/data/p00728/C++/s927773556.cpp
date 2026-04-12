#include <iostream>
#include <set>

using namespace std;

int main(){
     int N;
     while(cin>>N,N){
	  multiset<int> ten;
	  for(int i=0;i<N;i++){
	       int temp;
	       cin>>temp;
	       ten.insert(temp);
	  }
	  multiset<int>::iterator itr=ten.begin();
	  ten.erase(itr);
	  multiset<int>::reverse_iterator ritr=ten.rbegin();
	  ritr++;
	  ten.erase(ritr.base());
	  itr=ten.begin();
	  int sum=0;
	  while(itr!=ten.end()){
	       sum+=*itr;
	       itr++;
	  }
	  cout<<(int)sum/ten.size()<<endl;
     }
}