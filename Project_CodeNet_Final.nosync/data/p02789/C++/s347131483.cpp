#include<bits/stdc++.h>
//#include"Hamadneh"
using namespace std;

typedef int i32;
typedef long long i64;
typedef unsigned int u32;
typedef unsigned long long u64;

#define loop(i,n) for(i64 i = 0; i < (n); ++i)
#define pi  pair<int,int>
#define ti  tuple<int,int,int>
#define mt  make_tuple
#define mk  make_pair
#define vi  vector<int>
#define vll vector<i64>
#define fastInOut ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pr(a) for(auto x:a) cout<<x<<" ";
#define prmap(m) for(auto x:m) cout<<x.first<<" "<<x.second<<"\n";

i64 h,w,n;
int main() 
{ 
    fastInOut
    cin>>h>>w;
    if(h==w)
       cout<<"Yes";
    else 
       cout<<"No";
   return 0; 
} 