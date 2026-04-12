#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long  ULL;
typedef long long LL;

#define pb push_back
#define mp make_pair
#define reset(a, b) memset(a, b, sizeof(a))
#define rep(i,b) for(int i=0; i<b; i++)
#define F first 
#define S second

 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
//    cin>>T;
    T=1;
    while(T--){
       
       string s;
       cin>>s;
       
       if(s[0]==s[1] && s[1]==s[2]) cout<<"No";
       else cout<<"Yes";
       
       
       
    }
    
    return 0;
}