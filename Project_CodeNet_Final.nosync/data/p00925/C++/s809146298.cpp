#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<int,int> P;
const LL mod=1000000007;
const LL LINF=1LL<<62;
const LL INF=1<<17;


int main(){
    string s;
    int m;
    cin >> s >> m;
    int n=s.length();
    int a=s[0]-'0',b=0;
    for (int i = 1; i < n; i+=2) {
        if(s[i]=='+') a+=s[i+1]-'0';
        else a*=s[i+1]-'0'; 
    }
    bool c=false;
    int t=1;
    for (int i = 1; i < n; i+=2) {
        if(s[i]=='+'){
            if(c) b+=t*(s[i-1]-'0');
            else b+=s[i-1]-'0';
            t=1;
            c=false;
        }
        else{
            c=true;
            t*=s[i-1]-'0';
        }
    }
    if(c) b+=t*(s[n-1]-'0');
    else b+=s[n-1]-'0';
    if(m==a&&m==b) puts("U");
    else if(m==a&&m!=b) puts("L");
    else if(m!=a&&m==b) puts("M");
    else puts("I");
    return 0;
}

