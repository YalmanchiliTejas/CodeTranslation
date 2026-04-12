#include <bits/stdc++.h>
#define int long
#define ll long long
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
int gcd(int a,int b){return b ? gcd(b,a%b) : a;}
int lcm(int a,int b){return a/gcd(a,b)*b;}

main() {
    int N; cin >> N;
    map<char,int> m2;
    rep(i,N){
        string S; cin >> S;
        map<char,int> m;
        rep(j,S.size()){
            m[S[j]]++;
        }
        if(i==0){
            m2=m;
        }
        else{
            for(char c='a';c<='z';c++){
                m2[c]=min(m[c],m2[c]);
            }
        }
    } 
    for(char c='a';c<='z';c++){
        for(int i=0;i<m2[c];i++){
            cout << c;
        }
    }
    cout << endl;

    return 0;
}