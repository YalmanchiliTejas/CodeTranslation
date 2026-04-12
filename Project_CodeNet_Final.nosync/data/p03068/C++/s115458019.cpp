#include<bits/stdc++.h>
#define fi first
#define se second
#define bug cout<<"--------------"<<endl
using namespace std;
typedef long long ll;
const double PI=acos(-1.0);
const double eps=1e-6;
const int inf=1e9;
const ll mod=1e9+7;
const int maxn=1e5+10;
int n,k;
char s[15];
int main(){
    ios::sync_with_stdio(false);
    //cout<<(1ll<<62)<<endl;
    cin>>n>>s+1>>k;
    char c=s[k];
    for(int i=1;i<=n;i++){
        if(s[i]==c) cout<<s[i];
        else cout<<"*";
    }
	return 0;
}
