#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
    cin>>s;
    vector<int> check(2, 0);
    for(int i=0;i<3;i++){
        if(s[i] == 'A') check[0] += 1;
        else check[1] += 1;
    }
    if(check[0] == 0 || check[1] == 0) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
  
  return 0;
}