#include<bits/stdc++.h>
#define LL long long
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPA(i,n) for(int i=1;i<(n);++i)
#define PII pair<int,int>
#define PLI pair<long long, int>
#define PLL pair<long long, long long>
#define MOD ((int)1e6)
#define INF ((int)1e9)
#define INFLL ((LL)1e18)
#define ALL(x) (x).begin(),(x).end()
#define ctoi(x) (x - 'a') 
#define CTOI(x) (x - 'A')
#define BIT(x) (1 << (x))
#define PI (acos(-1))
using namespace std;

LL modinv(LL a){
    LL b = MOD, u = 1, v = 0;
    while(b){
        LL t = a / b;
        a -= t * b;swap(a, b);
        u -= t * v;swap(u, v);
    }
    u%=MOD;
    if(u < 0) u += MOD;
    return u;

}
LL exp(int a, int b){
    LL res = 1;
    LL sum = a;
    while(b){
        if(b&1)res = (res * sum) % MOD;
        sum = (sum * sum) % MOD;
        b>>=1;
    }
    return res;
}
int N;
vector<string> bytes;
vector<int> dp;
LL count(string a, string b){
    bool check=false;
    for(auto i:b)if(i=='y'){
        check=true;
        break;
    }
    if(check){
        bool flag = false;
        int xc = 0;
        int yc = 0;
        REP(i, a.size()){
            if(b[i]=='1'){
                if(a[i]=='0')return 0;
            }
            if(b[i]=='0'){
                if(a[i]=='1')return 0;
            }
            if(b[i]=='x'){
                if(a[i]=='x')++xc;
            }
            if(b[i]=='y'){
                if(a[i]=='1')flag=true;
                if(a[i]=='x')++yc;
            }
        }
        if(flag){
            return exp(2, xc + yc);
        }else{
            if(yc==0)return 0;
            return (exp(2, yc) - 1) * exp(2, xc);
        }
    }else{
        int count = 0;
        REP(i, a.size()){
            if(b[i]=='x'){
                if(a[i]=='x')++count;
            }else{
                if((a[i]!='x') and (a[i] != b[i]))return 0;
            }
        }
        return exp(2, count);
    }
} 

LL func(int place){
    if(place == N){
        return 1;
    }
    if(dp[place]>=0)return dp[place];
    LL res = (LL)func(place+1) * count(bytes[place], "0xxxxxxx");
    res %= MOD;
    if(place+2 <= N){
        res += (LL)func(place+2) * count(bytes[place]+bytes[place+1], "110yyyyx10xxxxxx");
        res %= MOD;
    }
    if(place+3 <= N){
        string str="";
        for(int i=0;i<3;++i)str += bytes[place+i];
        res += (LL)func(place+3) * count(str, "1110yyyy10yxxxxx10xxxxxx");
        res %= MOD;
    }
    if(place+4 <= N){
        string str="";
        for(int i=0;i<4;++i)str += bytes[place+i];
        res += (LL)func(place+4) * count(str, "11110yyy10yyxxxx10xxxxxx10xxxxxx");
        res %= MOD;
    }
    return dp[place] = res;
}

int main(){
    while(cin >> N && N){
        bytes = vector<string>(N);
        for(auto &i:bytes)cin >> i;
        dp = vector<int>(N, -1);
        cout << func(0) << endl;
    }
    return 0;
}

