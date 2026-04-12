#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define MIN(a,b) ((a) <= (b) ? (a) : (b))
#define ALL(v) (v).begin(), (v).end()
#define SORT(v) sort( ALL(v) )

using namespace std;
using ll = long long;
using P = pair<int,int>;

int main()
{

   string s;  cin>>s;
   if(s[0]=='A' && s[1] == 'A' && s[2]== 'A')
    cout<<"No"<<endl;
   else if(s[0]=='B' && s[1] == 'B' && s[2]== 'B')
    cout<<"No"<<endl;
    else
    cout<<"Yes"<<endl;

    return 0;
}
