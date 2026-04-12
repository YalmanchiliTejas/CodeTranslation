#define first f
#define second s
#define ll long long
#define mp make_pair
#define pb push_back
#define pf push_front
#define lb lower_bound
#define ub upper_bound
#include <bits/stdc++.h>
#define pii pair<int,int>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
const int maxn=1e5+5;
const int MOD=1e9+7;
const double PI=acos(-1);
const double e=2.718281828459;

int q[maxn],p[maxn];

int main()
{
    string s;
    cin>>s;
    bool fl=false,f=false;
    for(int i=0;i<3;i++){
        if(s[i]=='A'){fl=true;}
        if(s[i]=='B'){f=true;}
    }
    if(fl&&f){
        printf("Yes");
    }
    else{
        printf("No");
    }
    return 0;
}
