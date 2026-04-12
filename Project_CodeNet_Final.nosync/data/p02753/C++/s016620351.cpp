#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define max3(a,b,c) ((a>b)?(a>c)?a:c:(b>c)?b:c)
#define min3(a,b,c) ((a<b)?(a<c)?a:c:(b<c)?b:c)
#define testcase int t;cin>>t;while(t--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pll pair<long long int,long long int>
typedef long long int ll;
typedef unsigned long long int ull;
#define M 1000000007
using namespace std;
int main()
{
    fast
    string str;
cin>>str;
if(str[0]=='A'&&str[1]=='A'&&str[2]=='A'||str[0]=='B'&&str[1]=='B'&&str[2]=='B')
cout<<"No";
else
cout<<"Yes";
cout<<endl;
return 0;
}





