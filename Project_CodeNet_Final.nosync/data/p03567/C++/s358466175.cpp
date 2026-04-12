#include <iostream>
#include <vector>

#define rep(i,a) for(int i = 0 ; i < a ; i ++)
#define loop(i,a,b) for(int i = a ; i < b ; i ++)
#define vi vector<int>
#define vs vector<string>
#define pb push_back
using namespace std;

int main(void){
  string s;
  cin>>s;
  cout<<(s.find("AC") == -1 ?"No":"Yes")<<endl;
}