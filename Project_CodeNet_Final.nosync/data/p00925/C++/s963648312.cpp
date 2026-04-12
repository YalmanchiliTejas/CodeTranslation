#include<bits/stdc++.h>

using namespace std;
#define FOR(i,bg,ed) for(int i=bg;i<ed;i++)
#define REP(i,n) FOR(i,0,n)

typedef long long LL;
typedef vector<int> V;
string s;
int i(char x){
    return x-'0';
}
LL M(){
    LL sum=0;
    LL mul=i(s[0]);
    int id=1;
    int n=s.size();
    while(id<n){
        char op = s[id++];
        int num = i(s[id++]);
        if(op=='+'){
            sum += mul;
            mul = num;
        }
        if(op=='*'){
            mul*=num;
        }
    }
    sum+=mul;
    return sum;
}

LL L(){
    LL sum=i(s[0]);
    int id=1;
    int n=s.size();
    while(id<n){
        char op = s[id++];
        int num = i(s[id++]);
        if(op=='+'){
            sum += num;
        }
        if(op=='*'){
            sum*=num;
        }
    }
    return sum;
}
string ans[]={"I","L","M","U"};
        
int main(){
    LL ret;
    cin>>s>>ret;
    int x=0;
    if(M()==ret)x|=2;
    if(L()==ret)x|=1;
    cout<<ans[x]<<endl;
    return 0;
}