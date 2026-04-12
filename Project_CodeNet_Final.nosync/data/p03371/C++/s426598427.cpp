#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn=2e5+7;
int a[maxn];


int main (){
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    int ans2,ans1;
    if(x>=y){
        ans1=y*(a+b);
        ans1+=(x-y)*a;
        ans2=y*2*c;
        ans2+=(x-y)*a;
    }
    else {
        ans1=x*(a+b);
        ans1+=(y-x)*b;
        ans2=x*2*c;
        ans2+=(y-x)*b;
    }
    int ans=min(ans1,ans2);
    cout<<min(ans,min(a*x+b*y,max(x,y)*2*c))<<endl;
	return 0;
}
