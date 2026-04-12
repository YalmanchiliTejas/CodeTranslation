#include<bits/stdc++.h>

using namespace std;

int main() {
int a,b,c,x,y;
cin>>a>>b>>c>>x>>y;
int A =a*x+b*y;
int B=min(x,y);
int C=c*B*2;
int H=max(x,y);
if(max(x,y)==x&&x!=y){
   int D=(x-B)*a;
   int I=c*H*2;
   int E=min(A,min(I,(C+D)));
   cout<<E<<endl;
}
else{
int F=(y-B)*b;
int J= c*H*2;
int G=min(A,min(J,(C+F)));
cout<<G<<endl;

}


   return 0;
}




