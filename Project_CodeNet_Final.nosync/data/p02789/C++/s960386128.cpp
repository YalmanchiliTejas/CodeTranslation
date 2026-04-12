#include<iostream>
using namespace std;
int main()
{
	int n,m;
  	string ans;
	cin >> n >> m;
	
  	if(n == m){
      ans = "Yes";
    }else{
      ans = "No";
    }
	cout << ans << endl;
}