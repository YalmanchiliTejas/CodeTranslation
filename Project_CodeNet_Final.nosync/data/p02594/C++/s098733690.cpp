#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define fi first
#define se second
#define test ll int t;cin>>t;while(t--)
#define pll pair<long long,long long>
#define icc ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
long long power(long long a,long long b){
    long long ans=1;
    while(b>0){
        if(b&1){ans=(ans*a);}
                a=(a*a);
                b>>=1;
        }
    return ans;
}
int main(){
	icc
	int c;
	cin>>c;
	if(c>=30)cout<<"Yes\n";
	else cout<<"No\n";
	return 0;
}