#include<bits/stdc++.h>
#include<string>
using namespace std;
#define int long long
#define double long double
#define fo(a,b) for(int a=0;a<b;a++)
#define Sort(a) sort(a.begin(),a.end())
#define rev(a) reverse(a.begin(),a.end())
#define fi first
#define se second
#define pb push_back
#define pp() pop_back()
#define V vector
#define P pair
#define yuko(a) setprecision(a)
#define uni(a) a.erase(unique(a.begin(),a.end()),a.end())
#define Q queue
#define all(a)  (a).begin(),(a).end()
#define elif else if

signed main(){
  string s;
  cin>>s;
  int a=0;
  int b=0;
  fo(i,3){
    if(s[i]=='A')
      a++;
    else
      b++;

  }
  if(a&&b)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
}
