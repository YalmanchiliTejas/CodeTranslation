#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <set>

using namespace std;

int main(int argc, char *argv[])
{
  int size;

  cin >> size;
  vector<int> elem;
  set<int> elemset;
  for(int i=0;i<size;i++){
    int v;
    cin >> v;
    elem.push_back(v);
    elemset.insert(v);
  }

  sort(elem.begin(), elem.end());
  /*
  for(set<int>::iterator iter=elemset.begin();
      iter != elemset.end();iter++){
    cout << *iter << endl;
  }
  */
  int maxk=2;
  for(int i=0;i<elem.size();i++){
    for(int j=i+1;j<elem.size();j++){
      int difference=elem[j] - elem[i];
      //int num = elem[j];
      for(int k=1;k<elem[elem.size()-1];k++){
	int nextnum = elem[j] + k * difference;
	if(nextnum > elem[elem.size()-1]) break;
	//cout << k << " " << nextnum << " " << elem[i] << " " << elem[j] << endl;
	if(elemset.find(nextnum) != elemset.end()){
	  maxk = max(k+2, maxk);
	}else{
	  break;
	}
      }
    }
  }
  cout << maxk << endl;
  
  return 0;
}

