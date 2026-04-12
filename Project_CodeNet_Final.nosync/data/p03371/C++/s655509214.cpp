#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll=long long;
using P =pair<int,int>;

int main(){
int a,b,c,x,y;
cin>>a>>b>>c>>x>>y;
int ans;
if((a+b)>2*c){
if(x>=y){
ans=y*2*c+(x-y)*a;

}else{
ans=x*2*c+(y-x)*b;

}
if(ans>(2*c*max(x,y))){
ans=2*c*max(x,y);
}


}else{
ans=a*x+b*y;



}
cout<<ans<<endl;

}