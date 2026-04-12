#include <iostream>
#include <array>
#include <vector>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
using namespace std;

typedef  pair<int,int> P;
typedef long long LL;

const LL INF=300000000;
const LL MOD=1000000007;

LL gcd(LL a,LL b){
    if(b==0)return a;

    return gcd(b,a%b);
}

int main(){
    int n;
    cin>>n;
    int a[50][26]={};
    string s[50];
    for(int i=0;i<n;++i){
        cin>>s[i];
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<s[i].size();++j){
            a[i][s[i][j]-'a']++;
        }
    }
    string ans;
    for(int i=0;i<26;++i){
        int mi=10101010;
        for(int j=0;j<n;j++){
            mi=min(mi,a[j][i]);
        }
        for(int k=0;k<mi;++k){
            ans.push_back(i+'a');
        }
    }
    cout<<ans<<endl;
}