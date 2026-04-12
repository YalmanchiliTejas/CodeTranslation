#include <iostream>
#include <vector>
using namespace std;
     
int main() {
  while(true){
    vector<int> stones;
    int n,startC,lastC;
    int now;
    int last=0;
    stones.push_back(1);
    cin >> n;
    if(n==0)
      break;
    cin >> lastC;
    startC=lastC;
    for(int i=2;i<=n;i++){
      cin >> now;
      if(lastC==now)
	stones[last]++;
      else if(i%2==1){
	last++;
	stones.push_back(1);
    }
      else if(i%2==0){
	if(last!=0){
	  last--;
	  stones[last]+=1+stones[last+1];
	  stones.pop_back();
	}
	else{
	  stones[0]=i;
	  startC=now;
	}
      }
      lastC=now;
    }
    int a[2]={};
    for(int i=0;i<stones.size();i++){
      a[i%2]+=stones[i];
    }
    cout <<((startC==0)?a[0]:a[1]) << endl;
  }
  
  return 0;
}