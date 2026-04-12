/*g++ main.cpp -o main.out*/
/*./main.out*/

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define Mod 1000000007
#define L_Mod 17100000013

const double eps = 1e-9;
const int INF = 0x3f3f3f3f;
const double PI = 3.1415926535;

#define NO_TLE std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define ree(a,n) memset(a,n,sizeof(a));

#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define red(i,l,u) for(int (i)=(int)(l);(i)>=(int)(u);--(i))

int main()
{
    string s;
    cin>>s;
    if(s[0]==s[1]&&s[1]==s[2])cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
}
