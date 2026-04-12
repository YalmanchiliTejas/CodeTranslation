#include<iostream>
#include<map>
using namespace std;

string dir[6] = {"North", "East", "West", "South", "Right", "Left"};

int r[6][6] = { {1,5,2,3,0,4},
		{3,1,0,5,4,2},
		{2,1,5,0,4,3},
		{4,0,2,3,5,1},
		{0,2,4,1,3,5},
		{0,3,1,4,2,5} };

int main(){
  int n,d[6];
  string s;

  while(cin >> n,n){
    int ans = 1;
    for(int i=0;i<6;i++)d[i] = i+1;
    for(int i=0;i<n;i++){
      cin >> s;

      for(int j=0;j<6;j++){
	if(s == dir[j]){
	  int tmp[6];
	  for(int k=0;k<6;k++)tmp[k] = d[r[j][k]];
	  for(int k=0;k<6;k++)d[k] = tmp[k];
	  ans += d[0];
	}
      }
    }
    cout << ans << endl;
  }
}