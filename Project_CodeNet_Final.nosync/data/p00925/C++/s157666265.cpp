#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<iostream>
#include<cmath>
#include<map>
#include<set>
#include<climits>
using namespace std;
typedef vector<string>vs;
typedef vector<int>vi;
typedef vector<vi>vvi;
typedef vector<double>vd;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll>pll;
typedef vector<ll>vl;
typedef pair<int,pii>piii;
#define rrep(i,x,n) for(int i=(x);i<(n);++i)
#define rep(i,x) rrep(i,0,(x))
#define fi first
#define se second
#define each(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();++i)
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define pb push_back
#define maxs(a,b) (a)=max(a,b)
#define mins(a,b) (a)=min(a,b)
///#include<sstream>
///#include<cstring>
///#include<stack>
///#include<complex>

typedef string::const_iterator state;

int number(state &Begin){
    int ret=0;
    while(isdigit(*Begin)){
        ret=ret*10+(*Begin)-'0';
        Begin++;
    }
    return ret;
}

int multi(state &Begin){
    int ret=number(Begin);
    while(true){
        if(*Begin=='*'){
            Begin++;
            ret*=number(Begin);
        }
        else break;
    }
    return ret;
}

int solve1(state &Begin){
    int ret=multi(Begin);

    while(true){
        if(*Begin=='+'){
            Begin++;
            ret+=multi(Begin);
        }
        else break;
    }

    return ret;

}

int solve2(state &Begin){
    int ret=number(Begin);
    while(true){
        if(*Begin=='+'){
            Begin++;
            ret+=number(Begin);
        }
        else if(*Begin=='*'){
            Begin++;
            ret*=number(Begin);
        }
        else break;
    }
    return ret;
}
int main(){
    string str;
    int ans;
    cin>>str>>ans;
    str+="=";
    state b=str.begin();
    int f1=solve1(b);
    b=str.begin();
    int f2=solve2(b);
    if(f1==ans&&f2==ans)puts("U");
    else if(f1==ans)puts("M");
    else if(f2==ans)puts("L");
    else puts("I");
}