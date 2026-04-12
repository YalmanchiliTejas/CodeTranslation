#include <bits/stdc++.h>
#define int long long 
#define pb push_back
#define fr first
#define sc second
#define mp make_pair
#define all(a) a.begin(),a.end()
#define rep(i,a,n) for(int i=a;i<n;i++)
#define N 7200001
#define M 1000000007
using namespace std;
signed main(){
ios::sync_with_stdio(0);
cin.tie(0);
string s;
cin>>s;
if(count(all(s),'A')==0 || count(all(s),'B')==0)
cout<<"No"<<endl;
else cout<<"Yes"<<endl;

}