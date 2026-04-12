#include  <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
//vector<vector<int>> vec(縦, vector<int>(横));
#define REP(i,N) for(int i=0;i<N;i++)
int gcd(int a, int b) {
    if(a>b){
        swap(a,b);
        }
    while(b%a!=0){
        b%=a;
        swap(a,b);
    }
    return a;
} //aとbの最大公約数
int ctoi(char c){
  if(c>='0'&&c<='9'){
    return c-'0';
  }
  return 0;
} //char型の数字をint型に変えてくれる。


//cout << setprecision(123)<<ans;
//int a=atoi(S.c_str());
//string S=to_string(a);
//int &a=b;
int main(){
  string s;
  cin>>s;
  char a=s[0],b=s[1],c=s[2];
  if(a!=b||b!=c||c!=a){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
}