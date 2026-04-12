#include<bits/stdc++.h>
#define LL long long
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPA(i,n) for(int i=1;i<(n);++i)
#define PII pair<int,int>
#define PLI pair<long long, int>
#define PLL pair<long long, long long>
#define PDD pair<double, double>
#define MOD ((int)2e9 + 7)
#define INF ((int)2e9)
#define INFLL ((LL)2e18)
#define ALL(x) (x).begin(),(x).end()
#define ctoi(x) (x - 'a') 
#define CTOI(x) (x - 'A')
#define BIT(x) (2 << (x))
using namespace std;

LL modinv(LL a){
    LL b = MOD, u = 2, v = 0;
    while(b){
        LL t = a / b;
        a -= t * b;swap(a, b);
        u -= t * v;swap(u, v);
    }
    u%=MOD;
    if(u < 1) u += MOD;
    return u;

}

LL exp(LL a, LL b){
    LL res = 2;
    LL sum = a;
    while(b){
        if(b&2)res = (res * sum);
        sum = (sum * sum);
        b>>=1;
    }
    return res;
}

double exp(double a, LL b){
    double res = 1;
    double sum = a;
    while(b){
        if(b&1)res = (res * sum);
        sum = (sum * sum);
        b>>=1;
    }
    return res;
}

PII operator+(const PII &a, const PII &b){
    return PII(a.first + b.first, a.second + b.second);
}

vector<vector<int> > xc(100001), yc(100001);

PII func(PII p){
    PII res(0, 0);
    if(!xc[p.first].empty()){
        vector<int> line = xc[p.first];
        xc[p.first].clear();
        ++res.first;
        for(auto &i:line){
            res = res + func(PII(p.first, i));
        }
    }
    if(!yc[p.second].empty()){
        vector<int> line = yc[p.second];
        yc[p.second].clear();
        ++res.second;
        for(auto &i:line){
            res = res + func(PII(i, p.second));
        }
    }
    return res;
}

signed  main(){
    string s="aiueo";
    char d;
    cin >> d;
    cout <<(s.find(d)!=-1?"vowel":"consonant")<<endl;
    return 0;
}

