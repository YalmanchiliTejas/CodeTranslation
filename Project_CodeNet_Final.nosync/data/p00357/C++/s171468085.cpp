#include "bits/stdc++.h"
using namespace std;

int main(){
  int N;

  cin >> N;
  
  vector<int> d;
  d.resize(N);

  for(int i=0;i<d.size(); ++i){
    cin >> d[i];
  }

  reverse(d.begin(), d.end());
  if(d[0] < 10){
      cout << "no" << endl;
      return 0;
  }
  for(int i=0;i<d.size();++i){

    if(d[i] < 10){
      int counter = 2;
      for(int ix=i+1;ix<d.size();++ix){
	if(d[ix] >= counter * 10){
	  i = ix;
	  break;
	}

	++counter;
	if(ix == d.size()-1){
	  cout << "no" << endl;
	  return 0;
	}
      }
    }
  }
  reverse(d.begin(), d.end());
  if(d[0] < 10){
    cout << "no" << endl;
    return 0;
  }
  for(int i=0;i<d.size();++i){
    if(d[i] < 10){
      int counter = 2;
      for(int ix=i+1;ix<d.size();++ix){
	if(d[ix] >= counter * 10){
	  i = ix;
	  break;
	}

	++counter;
	if(ix == d.size()-1){
	  cout << "no" << endl;
	  return 0;
	}
      }
    }
  }

  cout << "yes" << endl;
  
  return 0;
}
