#include <bits/stdc++.h>
using namespace std;
//cin.ignore();	// better to use 2 times getline(cin,s);
// g++ iterator.cpp -std=c++17
//cout << (A + B == C ? "YES" : "NO") << endl;
#define pb push_back
#define mk make_pair
#define vll vector<ll>
#define mll map<ll,ll >
#define mlli map<ll,ll>::iterator
#define size size()
#define endl "\n"
#define ll long long int
#define ld long double
void fast(){
   	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);
   	cout.tie(NULL);}


int main(void)
{
  fast();
  string s;
  cin>>s;
  int cnta=0;
  int cntb=0;
  for(int i=0;i<s.size;i++)
  {
      if(s[i]=='A')
      {
          cnta++;
      }
      else
      {
          cntb++;
      }
  }
  if(cnta>=1 && cntb>=1)
  {
      cout<<"Yes"<<endl;
  }
  else
  {
      cout<<"No"<<endl;
  }
}