#include<bits/stdc++.h>
#define PB push_back
#define FO(i,a,b) for (int i = a; i <= b; i++)
#define FOb(i,a,b) for(int i=b;i>=a;i--)
#define vi vector<int>
#define vulli vector<unsigned long long int>
using namespace std;
typedef unsigned long long int ulli;
void solve()
{ 
  string str;
  cin>>str;
  if(str[0]==str[1] && str[1]==str[2])
    cout<<"No";
  else
    cout<<"Yes";
  

}
int main()
{
    std::ios_base::sync_with_stdio(false);
    ulli t=1;
   // cin>>t;   
    while(t--){ solve(); cout<<"\n"; }
    return 0;
}