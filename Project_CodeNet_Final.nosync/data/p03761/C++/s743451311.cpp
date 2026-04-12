#include<iostream>
#include<math.h>
#include<vector>
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
typedef vector<int> vec;
typedef vector<vector<int>> mat;

int main(){
    int N;cin>>N;
    vector<string> S(60);
    for(int i=0;i<N;i++)cin>>S[i];
    mat v(60,vec(30,0));
    vec M(30,10000000);
    for(int i=0;i<N;i++){
        for(int j=0;j<S[i].size();j++){
            int a=S[i][j]-'0'-49;
            v[i][a]++;
        }
        for(int k=0;k<26;k++)
            M[k]=min(M[k],v[i][k]);
    }
    for(int i=0;i<26;i++){
        char c=i+49+'0';
        for(int j=0;j<M[i];j++)
            cout<<c;
    }
    return 0;
}