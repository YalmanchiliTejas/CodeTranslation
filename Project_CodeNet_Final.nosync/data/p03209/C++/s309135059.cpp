#include <bits/stdc++.h>
#define sz(v)   ((int)(v).size())
#define  all(v)    ((v).begin()),((v).end())
#define  allr(v)    ((v).rbegin()),((v).rend())
#define   pb         push_back
#define   mp         make_pair
#define    Lcm(a,b)  ((a*b)/(__gcd(a,b)))
#define    clr(v,d)      memset( v, d ,sizeof(v))
typedef  long long     ll ;
typedef  unsigned long long     ull ;
const double eps= (1e-9);
using namespace std;
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
void GO(){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
ll P[60],C[60];
ll solve(ll lv,ll rem){
   // cout<<lv<<" "<<rem<<endl;
   if(rem<=0) return 0;
    if(lv==1){
        if(rem==1) return 0;
        else if(rem<5) return rem-1;
        else
            return rem-2;
    }
    if(rem==P[lv]){
        return C[lv];
    }
    if(rem==1){
        return 0;
    }
    ll ans=0;
    if(P[lv-1]+1>=rem){
        ans+=solve(lv-1,rem-1);
    }
    else if(P[lv-1]+2>=rem){
        ans+=1+solve(lv-1,rem-2);
    }
    else{
        ans+=C[lv-1]+1+solve(lv-1,rem-(P[lv-1]+2));
    }
   return ans;
}
ll test(int l,int x){
   ll cnt=0;
   string st="BpppB";
   for(int i=0;i<l-1;i++){
    st=("B"+st+"p"+st+"B");
   }
   for(int i=0;i<x;i++){
    if(st[i]=='p') cnt++;
   }
   return cnt;
}
int main(){
    GO();
    P[1]=5;
    C[1]=3;
    for(int i=2;i<=50;i++){
        P[i]=(P[i-1]*2+3);
        C[i]=(C[i-1]*2+1);
    }

    //cout<<C[2]<<" "<<P[2]<<endl;
    ll l,x;
    cin>>l>>x;
    if(l==1){
        if(x==1) cout<<"0\n";
        else if(x<5) cout<<x-1<<endl;
        else
            cout<<x-2<<endl;
        return 0;
    }
   cout<< solve(l,x) <<endl;

   //cout<<test(l,x)<<endl;
}






