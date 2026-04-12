#include<bits/stdc++.h>
#define int long long
using namespace std;

int hight(int a){return (int)pow(2,a+2)-3;}
int p(int a){return (int)pow(2,a+1)-1;}

int S(int l,int x){//レベルlのバーガーの下からx枚
int ans=0;
if(l==0){return x>=1;}
if(x<=1)return 0;
x--;
if(x<hight(l-1))return S(l-1,x);
x-=hight(l-1);ans+=p(l-1);  
if(x)ans++;
x--;
if(x<=0)return ans;
if(x<hight(l-1))return ans+S(l-1,x);
x-=hight(l-1);ans+=p(l-1);  
return ans;
}
signed main(){
int l,x;cin>>l>>x;
cout<<S(l,x)<<endl;
}