#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(a) (a).begin(),(a).end()
#define pb emplace_back
#define INF (1e9+1)

int main(){
    string s = "aiueo";
    
    
    char ch;
    cin>>ch;
    
    
    rep(i,s.size()){
        if(ch==s[i]){
            cout<<"vowel"<<endl;
            return 0;
        }
    }
    cout<<"consonant"<<endl;
}
