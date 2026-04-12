#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF= 1LL << 60;
#define REP(i,n) for(ll i=0; i<n; i++)
#define FOR(i,a,n) for(ll i=a; i<n; i++)
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    vector<string> S(n);
    map<char,int>A;

    REP(i,n){
        cin >> S[i];
    }
    REP(i,n){
        map<char,int>B;
        REP(j,S[i].length()){
            if(i==0) A[S[i][j]]++;
            else{
                B[S[i][j]]++;
            } 
        }
        
        REP(k,26){
            // cout << A[char('a'+k)];
            if(i!=0) A[(char)('a'+k)]= min(A[(char)('a'+k)], B[(char)('a'+k)]);
            // cout << B[(char)('a'+k)];
        }
            // cout << endl; 
        

    }
    // cout << char('a' +2) << endl;
    REP(k,26){
        int t= A[(char)('a'+k)];
        REP(i,t){
            // cout<<" SSS" << endl;
            cout << char('a'+k);
        }
    }cout << endl;
}