#include <bits/stdc++.h>
using namespace std;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define INF 100000000
typedef long long ll;

int main(){
    string S;
    cin>>S;
    if(S[0]==S[1]&&S[1]==S[2])cout<<"No";
    else cout<<"Yes";
    return 0;
}