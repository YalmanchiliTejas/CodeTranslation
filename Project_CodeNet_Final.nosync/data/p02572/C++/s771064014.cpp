#include <bits/stdc++.h>
using namespace std;
#define pi 2*asin(1.0)
#define MAX 10000000
#define MOD 1000000007
 
 
vector<long> fac(MAX);
vector<long> finv(MAX);
vector<long> inv(MAX);
 
//template functions
/////////////////////////
void Cominit(){
  fac.at(0)=fac.at(1)=1;
  finv.at(0)=finv.at(1)=1;
  inv.at(1)=1;
  for(long i=2;i<MAX;i++){
      fac.at(i)=(fac.at(i-1)*i)%MOD;
      inv.at(i)=MOD-inv.at(MOD%i)*(MOD/i)%MOD;
      finv.at(i)=finv.at(i-1)*inv.at(i)%MOD;
  }
}

long facComb(long N,long M){// nCm%
if(N<M) return 0;
if(N<0||M<0) return 0;
return fac.at(N)*(finv.at(M)*finv.at(N-M)%MOD)%MOD;
}

long Comb(long N,long M){// nCm
long ans=1;
for(long i=N;i>N-M;i--){
    ans=ans*i;
}
for(long i=M;i>0;i--){
    ans=ans/i;
}
return ans;
}

long Perm(long N,long M){// nPm
long ans=1;
for(long i=N;i>N-M;i--){
    ans=ans*i;
}
return ans;
}

long GCM(long A,long B){
            long W,r;
    if(A<B){

        W=B;
        B=A;
        A=W;
    }
    while(A%B!=0){
        r=A%B;
        A=B;
        B=r;
    }
    return B;
}
long LCM(long A,long B){
    return (A*B)/GCM(A,B);
}

long upDiv(long a,long b){
  return (a+b-1)/b;
}

/////////////////////////


//Answer


int main() {
long N;
cin>>N;
long sum=0;
long long sq=0;
long long divsq=0;
long div=0;
vector<long> A(N);
for(long i=0;i<N;i++){
cin>>A.at(i);
sum+=A.at(i);
sq+=A.at(i)*A.at(i);
div+=sum/MOD;
sum=sum%MOD;
divsq+=sq/MOD;
sq=sq%MOD;
}
if((div-divsq)%2==0){
    cout<<((sum*sum-sq)/2)%MOD<<endl;
}else{
    cout<<((sum*sum-sq+MOD)/2)%MOD<<endl;
}



}

