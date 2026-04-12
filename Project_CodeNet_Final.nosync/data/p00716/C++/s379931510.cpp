#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
  int m;
  cin >>m;
  while(m--){
    long long int money;
    vector<long long int> ans;
    int year,n;
    cin >>money>>year;
    cin >>n;
    while(n--){
      int f,x;
      double a;
      long long int b = money;
      cin >>f>>a>>x;
      if(f == 0){
	long long int c = 0;
	for(int i=0; i<year; i++){
	  c+=b*a;
	  b-=x;
	}
	ans.push_back(b+c);
      }
      else{
	for(int i=0; i<year; i++) b+=b*a-x;
	ans.push_back(b);
      }
    }
    sort(ans.begin(),ans.end());
    cout <<ans[ans.size()-1]<<endl;
  }
  return 0;
}