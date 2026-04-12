#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>
using namespace std;

void rist_hen(int hu);
vector<int> batu;
int ristl[1111],ristr[1111];
int n,flag;

int main(){
  string str[3] = {"Fizz" , "Buzz" , "FizzBuzz" };
  int m;
  string s;
  while(cin >> n >> m && n && m){
    flag = n;
    for(int i=0;i<n;i++){
      ristl[i] = i-1;
      ristr[i] = i+1;
    }
    ristr[n-1] = 0;
    ristl[0] = n-1;
    batu.clear();
    int now = 0;
    for(int i=1;i<=m;i++){
      cin >> s;
      if(flag == 1) continue;
      if(i%3 == 0 && i%5 == 0){
	if(s != str[2]) rist_hen(now);
      }
      else if(i%3 == 0){
	if(s != str[0]) rist_hen(now);
      }
      else if(i%5 == 0){
	if(s != str[1]) rist_hen(now);
      }
      else {
	stringstream ss;
	ss << i;
	string tmp = ss.str();
	if(s != tmp) rist_hen(now);
      }
      now = ristr[now];
    }
    int ans[111111];
    int cou = 0;
    for(int i=1;i<=n;i++){
      vector<int>::iterator it;
      it = find(batu.begin(),batu.end(),i);
      if(it != batu.end());
      else{
	ans[cou] = i;
	cou++;
      }
    }
    for(int i=0;i<cou;i++){
      cout << ans[i];
      if(cou-1 == i) cout << endl;
      else cout << " ";
    }
  }
}

void rist_hen(int hu){
  //cout << "HU = " << hu << endl;
  ristl[ristr[hu]] = ristl[hu];
  ristr[ristl[hu]] = ristr[hu];
  batu.push_back(hu+1);
  flag--;
  return;
}