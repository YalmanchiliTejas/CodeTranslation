



#include <bits/stdc++.h>
#include <string.h>
#include <vector>
//s#define rep(i, n) for (int i = 0; i < (n); i++)
#define MAX 10000

using namespace std;

#define ll long long
#define pb push_back
//#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define rep(i,a,n) for(int i=a; i<n; i++)
#define r0 return 0
#define INF (int)1e15
#define MOD 1000000007

map<char,int>mp[100];
map<char,int>::iterator it;

 int main(){

  long long n,c=0,d=0;
  char ch;
  string s,s1;
  cin>>n;

  for(int i=0;i<n;i++)
 {
    cin>>s;
    if(i == 0)s1 = s;
    for(int j=0;j<s.length();j++)
    {
        mp[i][s[j]]++;
    }
  }


  for(it = mp[0].begin();it!=mp[0].end();++it)
 {

    ch = it->first;
    d = it->second;
   // cout<<ch<<" ? "<<d<<endl;
     for(int i=1;i<n;i++){
 //       cout<<"character "<<mp[i][ch]<<endl;
        c = mp[i][ch];
        if(d>c){ d = c;}
     }
     // cout<<ch<<" // "<<d<<endl;
     for(int j=0;j<d;j++){
        cout<<ch;
     }

  }





 return 0;
 }

