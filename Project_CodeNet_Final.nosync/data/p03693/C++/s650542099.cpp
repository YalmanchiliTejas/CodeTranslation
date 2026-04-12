#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

  int a,b,c;cin>>a>>b>>c;
  int t = a*100+b*10+c;
  if(t%4==0){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;

  }

  return 0;
}
