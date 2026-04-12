#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <math.h>
#include <complex>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <bitset>
#include <functional>
#include <assert.h>
#define int long
#define ll long long
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define eb emplace_back
#define all(x) x.begin(),x.end()
#define SZ(x) x.size()
#define fi first
#define se second
const int INF = 1e9;
using namespace std;

template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;

using pi=pair<int,int>;
using vi=vc<int>;

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout<<fixed<<setprecision(20);

    int N; cin >> N;
    string S; cin >> S;
    string A="SS",B="SW",C="WS",D="WW";
    rep(i,N-1){
        if(A[i+1]=='S'){
            if(S[i+1]=='o'){
                if(A[i]=='S') A+='S';
                else A+='W';
            } else {
                if(A[i]=='S') A+='W';
                else A+='S';
            }
        } else {
            if(S[i+1]=='o'){
                if(A[i]=='S') A+='W';
                else A+='S';
            } else {
                if(A[i]=='S') A+='S';
                else A+='W';
            }
        }
    }
    rep(i,N-1){
        if(B[i+1]=='S'){
            if(S[i+1]=='o'){
                if(B[i]=='S') B+='S';
                else B+='W';
            } else {
                if(B[i]=='S') B+='W';
                else B+='S';
            }
        } else {
            if(S[i+1]=='o'){
                if(B[i]=='S') B+='W';
                else B+='S';
            } else {
                if(B[i]=='S') B+='S';
                else B+='W';
            }
        }
    }
    rep(i,N-1){
        if(C[i+1]=='S'){
            if(S[i+1]=='o'){
                if(C[i]=='S') C+='S';
                else C+='W';
            } else {
                if(C[i]=='S') C+='W';
                else C+='S';
            }
        } else {
            if(S[i+1]=='o'){
                if(C[i]=='S') C+='W';
                else C+='S';
            } else {
                if(C[i]=='S') C+='S';
                else C+='W';
            }
        }
    }
    rep(i,N-1){
        if(D[i+1]=='S'){
            if(S[i+1]=='o'){
                if(D[i]=='S') D+='S';
                else D+='W';
            } else {
                if(D[i]=='S') D+='W';
                else D+='S';
            }
        } else {
            if(S[i+1]=='o'){
                if(D[i]=='S') D+='W';
                else D+='S';
            } else {
                if(D[i]=='S') D+='S';
                else D+='W';
            }
        }
    }
    bool frag=false;
    if(A[N] == A[0]){
        if(A[0]=='S' && S[0]=='o' || A[0]=='W' && S[0]=='x'){
            if(A[1]=='S'){
                if(A[N-1]=='S') frag=true;
            } else {
                if(A[N-1]=='W') frag=true;
            } 
        } else if(A[0]=='S' && S[0]=='x' || A[0]=='W' && S[0]=='o'){
            if(A[1]=='S'){
                if(A[N-1]=='W') frag=true; 
            } else {
                if(A[N-1]=='S') frag=true;
            }
        }
        if(frag) {
            A.erase(A.end()-1);
            cout << A << endl;
            return 0;
        }
    }
    if(B[N] == B[0]){
        if(B[0]=='S' && S[0]=='o' || B[0]=='W' && S[0]=='x'){
            if(B[1]=='S'){
                if(B[N-1]=='S') frag=true;
            } else {
                if(B[N-1]=='W') frag=true;
            } 
        } else if(B[0]=='S' && S[0]=='x' || B[0]=='W' && S[0]=='o'){
            if(B[1]=='S'){
                if(B[N-1]=='W') frag=true; 
            } else {
                if(B[N-1]=='S') frag=true;
            }
        }
        if(frag) {
            B.erase(B.end()-1);
            cout << B << endl;
            return 0;
        }
    }
    if(C[N] == C[0]){
        if(C[0]=='S' && S[0]=='o' || C[0]=='W' && S[0]=='x'){
            if(C[1]=='S'){
                if(C[N-1]=='S') frag=true;
            } else {
                if(C[N-1]=='W') frag=true;
            } 
        } else if(C[0]=='S' && S[0]=='x' || C[0]=='W' && S[0]=='o'){
            if(C[1]=='S'){
                if(C[N-1]=='W') frag=true; 
            } else {
                if(C[N-1]=='S') frag=true;
            }
        }
        if(frag) {
            C.erase(C.end()-1);
            cout << C << endl;
            return 0;
        }
    }
    if(D[N] == D[0]){
        if(D[0]=='S' && S[0]=='o' || D[0]=='W' && S[0]=='x'){
            if(D[1]=='S'){
                if(D[N-1]=='S') frag=true;
            } else {
                if(D[N-1]=='W') frag=true;
            } 
        } else if(D[0]=='S' && S[0]=='x' || D[0]=='W' && S[0]=='o'){
            if(D[1]=='S'){
                if(D[N-1]=='W') frag=true; 
            } else {
                if(D[N-1]=='S') frag=true;
            }
        }
        if(frag) {
            D.erase(D.end()-1);
            cout << D << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}