#include<bits/stdc++.h>
using namespace std;

int main(){
  string str;
  string S[100];
  int n, abc[100][100] = {}, temp;
  cin>>n;

  for(int i = 0; i < n; i++){
       cin>>S[i];
        int s = S[i].size();
       // sort(S[i].begin(), S[i].end());
       // cout<<S[i]<<endl;
       for(int j = 0; j < s; j++){
	 temp = S[i][j] - 'a';//cout<<temp<<endl;
	 abc[i][temp]++; 
       }
  }
  for(int j = 0; j < 26; j++){
    int mi = 10000000;
    for(int i = 0; i < n; i++){
      mi = min(mi, abc[i][j]);
    }
    for(int i = 0; i < mi; i++){
      cout<<(char)('a'+j);
    }
  }
  
  cout<<endl;
  return 0;
}
