#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse2")

#include<bits/stdc++.h>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
using namespace std;

#define int         long long
#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define mp          make_pair
#define all(a)      (a).begin(),(a).end()
#define FF           first
#define SS           second
#define sz(x)       (int)x.size()
#define endl        '\n'
//#define hell          1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
// mp::cpp_int
#define pp pair<pii,pii>
const int hell =1000000007;



int power(int a,int b)
{
  if(b==0)return 1;
  if(b==1)return a;
  int t=power(a,b/2);
  t%=hell;
  t*=t;
  t%=hell;
  if(b%2)return (t*a)%hell;
  else
     return t;
}
int p[100000]={0};
bool b[100000]={false};

void pri()
{
  

  rep(i,2,100000)
  for(int j=i+i;j<100000;j+=i)b[j]=true;

    rep(i,2,100000)if(b[i]==false)p[i]=1;
}



int solve( ){

int n;
  cin>>n;
int mx=0;
int ans=0;
rep(i,0,n)
{
	int a;
	cin>>a;
	if(a>=mx)ans++;
	mx=max(mx,a);
}

cout<<ans;

return 0;
}



signed main()
{  int t=1;
 ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   cin.exceptions(cin.failbit);
 
 // pri();
  clock_t time_req;

    // Without using pow function
    time_req = clock();
    
//cin>>t;
    int k=1;
   while(t--)
     {
       //cout<<"case #"<<k<<":"<<" ";k++;
      solve();
     }

         time_req = clock() - time_req;
   //cout << "Processor time taken is "
     // << (double)time_req/CLOCKS_PER_SEC << " seconds" << endl;


    return 0;
}

