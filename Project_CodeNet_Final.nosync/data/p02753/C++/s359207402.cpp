#include <bits/stdc++.h>
#define log(x) cout<<x<<endl
#define pb push_back
#define rep(i,n) for(int i = 0;i < n;++i)
using namespace std;

int main() {
    string S;
    cin>>S;
    if(S[0]==S[1] && S[1] == S[2]){
      log("No");
    }else{
      log("Yes");
    }
}