#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define MIN(a,b) ((a)>(b)? (b): (a))
#define MAX(a,b) ((a)<(b)? (b): (a))

const long long INF = 1LL << 60;
typedef unsigned long long ll;
const long long MOD = 1000000000 + 7;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    rep(i,4){
        char res[n+2];    
        if(i%2 == 0) res[0] = 'S';
        else res[0] = 'W';
        if(i/2 == 0) res[1] = 'S';
        else res[1] = 'W';
        rep(j,n){
            char bs = res[j];
            char ns = res[j+1];
            if(bs == 'S' && ns == 'S' ){
                if(s[j] == 'o') res[j+2] = 'S';
                else res[j+2] = 'W'; 
            }else if(bs == 'S' && ns == 'W'){
                if(s[j] == 'o') res[j+2] = 'W';
                else res[j+2] = 'S';                 
            }else if(bs == 'W' && ns == 'S'){
                if(s[j] == 'o') res[j+2] = 'W';
                else res[j+2] = 'S'; 
            }else if(bs == 'W' && ns == 'W'){
                if(s[j] == 'o') res[j+2] = 'S';
                else res[j+2] = 'W'; 
            }    
        }
        if (res[n] == res[0] && res[n+1] == res[1]){
            for(int j = 1; j< n+1; j++) cout << res[j] ;
            cout << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}