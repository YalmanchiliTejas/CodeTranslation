#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
const int N = 1e5 + 7, M = 1e7, OO = 0x3f3f3f3f;
#define AC ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); cin.sync_with_stdio(0);
int main()
{
int n,i;
string ans="";
vector<int>freq(27,OO);
scanf("%d",&n);
while(n--){
    vector<int>freq2(27,0);
    string s;
    cin>>s;
    int n1=s.size();
    for(i=0;i<n1;++i){
        freq2[s[i]-'a']++;
    }
    for(i=0;i<27;++i){
        freq[i]=min(freq[i],freq2[i]);
    }
}
for(i=0;i<27;++i){
    for(int j=0;j<freq[i];++j){
        ans+=('a'+i);
    }
}
cout<<ans;


    return 0;
}
