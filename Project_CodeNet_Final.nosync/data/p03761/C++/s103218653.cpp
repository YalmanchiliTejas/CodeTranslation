#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
#define PI 3.14159265358979323846264338327950L
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    int n;
    cin>>n;
    vector<int> A(26,50);//aの出現回数=A[0]…zの出現回数=A[25]とする
    rep(i,n){
        string S;
        cin>>S;
        vector<int> B(26,0);
        for(auto c:S) B[c-'a']++;//Sを1文字ずつカウントする
        rep(i,26) A[i]=min(A[i],B[i]);//各文字の出現回数をAに入れる
    }
    rep(i,26){
        rep(j,A[i]){
            cout<<(char)(i+'a');//a~zをA[i]回出力
        }
    }
    cout<<endl;
}