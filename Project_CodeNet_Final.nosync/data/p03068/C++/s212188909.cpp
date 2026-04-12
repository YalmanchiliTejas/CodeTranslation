#include <bits/stdc++.h>
#define vel vector<long long>
#define veb vector<bool>
#define vvel vector<vel>
#define int long long
#define pin pair<int,int>
#define ppin pair<int,pin>
#define mkp make_pair
#define rep(i,n) for(int i=0;i<n;i++)
#define maxel(vec, j) *max_element(vec.begin(), vec.begin()+j)

using namespace std;
void mmin(int &a, int b) { a = min(a, b); }
void mmax(int &a, int b) { a = max(a, b); }
signed main() {
    int pr = 1000;
    pr *= pr * pr; pr += 7;
    int N, K;
    string S;
    cin >> N;
    cin >> S;
    cin >> K;
    char s = S[K-1];
    rep(i, N){
        if(S[i] == s){
            cout<<s;
        }else{
            cout<<'*';
        }
    }
    return 0;
}
