#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
typedef long long LL;
int main(){
    int A,B,C;
    cin>>A>>B>>C;
    if((A*100+B*10+C)%4==0){
       cout<<"YES"<<endl;
    }else{
       cout<<"NO"<<endl;
    }
	return(0);
}