#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void){
  int n;
  while(1){
    cin>>n;
    vector<int> score;
    if(n==0){break;}
    for(int i=0;i<n;i++){
      int tmp;
      cin>>tmp;
      score.push_back(tmp);
    }
    sort(score.begin(),score.end());
    int mean=0;
    for(int i=1;i<n-1;i++){
      mean+=score[i];
    }
    mean=mean/(n-2);
    cout<<mean<<endl;
  }
  return 0;
}

