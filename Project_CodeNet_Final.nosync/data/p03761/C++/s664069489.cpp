#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n+1); i++)
int main() {
 int N;
 cin>>N;
 vector<string>S(N);
 vector<int>ans(26);
 rep(i,N){
      vector<int>cnt(26);
   	rep(j,26){
    cnt[j]=0;}
    cin>>S[i];
   string C=S[i];
    rep(j,C.size()){
        cnt[int(C[j])-97]++;
    }
    if(i==0){
        rep(i,26){
            ans[i]=cnt[i];
        }
    }
    else{
        rep(i,26){
            if(cnt[i]<ans[i]){
                ans[i]=cnt[i];
            }
        }
    }
 }
 rep(i,26){
     rep(j,ans[i]){
cout<<char(i+97);
     }
 }
 cout<<""<<endl;
}
