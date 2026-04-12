#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
struct point{int x;int y;};
int i,j,k,count1=0,count2=0;

int main(){
    int n,k;
    string s;
    cin>>n>>s>>k;
    rep(i,n){
        if(s[i]!=s[k-1])s[i]='*';
    }
    cout<<s<<endl;
}