#include<iostream>
#include<math.h>
#include<vector>
#include<array>
#include<algorithm>
#include<numeric>
#include<map>
#include<queue>
#include<deque>
#include<set>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vector<ll>> mat;
typedef pair<int,int> P;
ll mod=pow(10,9)+7;
ll INF=pow(10,18);

int main(){
    string S;cin>>S;
    if(S[0]=='A' && S[1]=='A' && S[2]=='A') cout<<"No"<<endl;
    else if(S[0]=='B' && S[1]=='B' && S[2]=='B') cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
    return 0;
}