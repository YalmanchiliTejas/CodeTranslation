#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
typedef long long int ll;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define in insert
#define For(i,n) for(ll i = 0 ; i < n ; i++)

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);cout.tie(NULL);
  string s;
  cin>>s;
  ll a = 0 , b = 0;
  For(i,3){
    if(s[i] == 'A')a++;
    else b++;
  }
  if(a && b )cout<<"Yes";
  else cout<<"No";
}