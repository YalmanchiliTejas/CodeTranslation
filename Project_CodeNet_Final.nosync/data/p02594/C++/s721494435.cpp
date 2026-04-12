#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
long long mx(long long a,long long b){if(a>b)return a;else return b;}
long long mn(long long a,long long b){if(a<b)return a;else return b;}
long long cei(long long a,long long b){if(a%b==0)return a/b;else return (a/b+1);}
const int MOD=1e9+7;
long long po(long long a,long long b){long long res=1;while(b>0){res=(res*a);res%=MOD;b--;}return res;}


int main()
{
int x;
cin>>x;
if(x>=30)cout<<"Yes"<<endl;
else
cout<<"No"<<endl;



}