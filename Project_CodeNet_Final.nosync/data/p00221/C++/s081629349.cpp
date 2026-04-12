#include "bits/stdc++.h"
using namespace std;

typedef long long lli;
typedef pair<int,int> pii;
#define rep(i,n) for(lli i=0;i<(lli)(n);i++)
#define all(a)  (a).begin(),(a).end()
#define pb push_back
#define INF 999999999


string fb(int n){
    if(n%15==0)return "FizzBuzz";
    if(n%5==0)return "Buzz";
    if(n%3==0)return "Fizz";
    stringstream ss;
    ss<<n;
    return ss.str();
}


int main(){
    int n,m;
    while(cin>>m>>n){
        if(n==0&&m==0)break;
        
        int mem[2000]={};
        rep(i,m) mem[i]=i;
        int less=m;
        
        
        int c=0;
        rep(i,n){
            string a;
            cin>>a;
            if(less==1)continue;
            string teac = fb(i+1);
            
            
            if(teac!=a){
                while(mem[c]==-1)c=(c+1)%m;
                mem[c]=-1;
                less--;
            }else{
                while(mem[c]==-1)c=(c+1)%m;
                c=(c+1)%m;
            }
            
    
        }
        
        bool f=false;
        rep(i,m){
            if(mem[i]!=-1){
                if(f)cout<<" ";
                f=true;
                cout<<mem[i]+1;
            }
        }
        cout<<endl;
        
    }
}