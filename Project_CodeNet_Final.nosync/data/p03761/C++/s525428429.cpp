#include <iostream>
#include <string>
using namespace std;

int array[50][26];

int ctoi(char ch){ //a → 0
  return ch-'a';
}
char itoc(int n){
  return n+'a';
}
int main(){
  int n;  cin>>n;
  for(int i=0;i<n;i++){
    string temp;
    cin>>temp;
    for(int j=0;j<temp.size();j++){
      array[i][ctoi(temp[j])]++;
    }
  }

  for(int i=0;i<26;i++){
    int mini=99999;
    for(int j=0;j<n;j++){
       mini = min(mini,array[j][i]);
    }
    for(int k=0;k<mini;k++){
      cout<<itoc(i);
    }
  }
  cout<<"\n";
}
