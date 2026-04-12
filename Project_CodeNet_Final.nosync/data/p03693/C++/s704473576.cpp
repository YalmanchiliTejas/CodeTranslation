#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(inti=a;i<=b;i++)

#define MOD 1000000009
typedef long long int ll;
typedef vector<int>vi;
typedef pair<int,int>pi;


int main()
{
int r,g,b;
cin>>r>>g>>b;
int l=r*100+g*10+b;
if(l%4)
    cout<<"NO"<<endl;
else
    cout<<"YES"<<endl;
 return 0;
}
