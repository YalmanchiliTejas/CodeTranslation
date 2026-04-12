#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
ll A,B,C,X,Y;
cin>>A>>B>>C>>X>>Y;
ll sum[3];
sum[0]=A*X+B*Y;
sum[1]=min(X,Y)*C*2;
sum[2]=max(X,Y)*C*2;
if(X>Y) sum[1]+=(X-Y)*A;
if(Y>X) sum[1]+=(Y-X)*B;
sort(sum,sum+3);
cout<<fixed<<setprecision(0)<<sum[0];
return 0;
}
