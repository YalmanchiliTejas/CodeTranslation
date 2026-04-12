#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main(){
   char c;cin >>c;
   char x[5]={'a','i','u','e','o'};
   bool flg=false;
    for (int i = 0; i < 5; ++i) {
        if(c==x[i])flg=true;
    }
    if(flg)puts("vowel");
    else puts("consonant");
   return 0;
}