#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
void make_unique(vector<ll> vec)
{
sort(all(vec));
vec.resize(unique(all(vec)) - vec.begin());
}

int main() 
{   //int t;
    //cin>>t;
    //while(t--)
    //{ll k,n,m,i,j,flag=0,count=0,s=0;
    // cin>>n;
     //vector<ll> v(n);
      
    //  for(auto &i: v)
     // cin>>i;
     int x;
     cin>>x;
     if(x>=30)
     cout<<"Yes"<<endl;
     else 
     cout<<"No"<<endl;
      
    
   // }
    
    
	return 0;
}
