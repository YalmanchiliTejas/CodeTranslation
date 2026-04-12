    #include<bits/stdc++.h>
    using namespace std;
    #define rep(i, n) for (int i = 0; i < (int)(n); ++i)
    #define rep2(i, s, n) for (int i = (s); i < (int)(n); ++i)
    #define chmax(a, b) a = max(a, b)
    #define chmin(a, b) a = min(a, b)
    #define fi first
    #define se second
    #define INF 1000000009
    #define LLINF 1000000000000000009LL
    using ll = long long;
     
    char x[]={'a','i','u','e','o'};
     
    int main(){
      char c;
      cin>>c;
      rep(i,5){
        if(c==x[i]){
          cout<<"vowel"<<endl;
          return(0);
        }
      }
      cout<<"consonant"<<endl;
      return(0);
    }