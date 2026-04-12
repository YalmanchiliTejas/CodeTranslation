#include<bits/stdc++.h>
#include<cstdio>

using namespace std;

typedef long long int ll;

template<class T> inline bool chmax(T& a,T b){ if(a<b){ a=b; return true;} return false; }
template<class T> inline bool chmin(T& a,T b){ if(a>b){ a=b; return true;} return false; }

typedef pair<int,int> pair;

int main(){
    string s;
    int ans=0;
    cin >> s;

    if(s[0]==s[1] && s[1]==s[2]){
        puts("No");
        return 0;
    }
    puts("Yes");
}